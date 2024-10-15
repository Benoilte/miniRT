/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/15 22:23:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	update_progress(t_data *data, int line_finished)
{
	static int	line_count = 0;

	if (print_mutex(PRINT_MTX_LOCK) != 0)
	{
		ft_printf("\r\r\r");
		return ;
	}
	if (line_finished == 0)
		line_count = 0;
	else
	{
		line_count++;
		if (line_count == data->resolution.y)
			ft_printf("\rRender complete!");
		else
			ft_printf("\r%i %%", (line_count * 100) / data->resolution.y);
	}
	print_mutex(PRINT_MTX_UNLOCK);
}

void	*render_strip(void *arg)
{
	t_render_info	*info;
	t_pixel			pixel;
	t_ray			ray;
	t_color			color;
	int				color_int;

	info = (t_render_info *)arg;
	pixel.y = info->start_line;
	while (pixel.y < info->stop_line)
	{
		pixel.x = -1;
		while (++(pixel.x) < info->data->resolution.x)
		{
			ray = ray_for_pixel(*(info->data->camera), pixel.x, pixel.y);
			if (color_at(&color, NULL, &ray, info) != 0)
				return (print_error("render_strip", THREAD_ERROR), (void *)1);
			color_int = rgb_stoi(color);
			if (color_int != 0)
				set_pixel_color(info->data, pixel.x, pixel.y, color_int);
		}
		update_progress(info->data, 1);
		pixel.y++;
	}
	return ((void *)0);
}

void	render(t_data *data)
{
	t_thread_info	thread;

	if (!data)
		return ;
	reset_image(data);
	ft_printf("Rendering...\n");
	thread.count = data->render.thread_count;
	thread.created = create_threads(data);
	if (!thread.created)
		exit_error(data, NO_THREAD_ERROR);
	thread.errors = join_threads(data);
	ft_printf("\n");
	handle_any_thread_errors(data, thread);
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
							data->mlx->img, 0, 0);
}

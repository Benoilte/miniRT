/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/05 16:01:02 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	update_progress(t_data *data, int line_finished)
{
	static int	line_count = 0;

	pthread_mutex_lock(&data->render.print_lock);
	if (line_finished == 0)
	{
		line_count = 0;
		ft_printf("Rendering...\n");
	}
	else
	{
		line_count++;
		if (line_count == WIN_HEIGHT)
			ft_printf("\rRender complete!\n");
		else
			ft_printf("\r%i %%", (line_count * 100) / WIN_HEIGHT);
	}
	pthread_mutex_unlock(&data->render.print_lock);
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
		while (++(pixel.x) < WIN_WIDTH)
		{
			ray = ray_for_pixel(*(info->data->camera), pixel.x, pixel.y);
			info->reflective_depth = REFLECTIVE_DEPTH;
			if (color_at(&color, NULL, &ray, info) != 0)
				return (print_error("render_strip", "aborting thread"), NULL);
			color_int = rgb_stoi(color);
			if (color_int != 0)
				set_pixel_color(info->data, pixel.x, pixel.y, color_int);
		}
		update_progress(info->data, 1);
		pixel.y++;
	}
	return (NULL);
}

void	render(t_data *data)
{
	if (!data)
	{
		print_error("render", INVALID_POINTER);
		return ;
	}
	ft_printf("Render with %d threads\n", data->render.thread_count);
	reset_image(data);
	update_progress(data, 0);
	create_threads(data);
	join_threads(data);
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
							data->mlx->img, 0, 0);
}

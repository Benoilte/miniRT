/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/30 17:10:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	update_progress(t_data *data, int line_finished)
{
	static int	line_count = 0;

	pthread_mutex_lock(&data->print_lock);
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
	pthread_mutex_unlock(&data->print_lock);
}

static void	*render_strip(void *arg)
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
			if (color_at(&color, &ray, info) != 0)
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
	int			i;

	if (!data)
	{
		print_error("render", INVALID_POINTER);
		return ;
	}
	reset_image(data);
	update_progress(data, 0);
	i = 0;
	while (i < THREAD_COUNT)
	{
		if (pthread_create(&data->threads[i], NULL, render_strip, \
							&data->render[i]))
			exit_error(data, "pthread creation error");
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
		if (pthread_join(data->threads[i++], NULL))
			exit_error(data, "pthread join error");
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
							data->mlx->img, 0, 0);
}

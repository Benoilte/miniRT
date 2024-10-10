/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/10 18:18:38 by bgolding         ###   ########.fr       */
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
	{
		line_count = 0;
		ft_printf("Rendering...\n");
	}
	else
	{
		line_count++;
		if (line_count == data->resolution.y)
			ft_printf("\rRender complete!\n");
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
				return (print_error("render_strip", "aborting thread"), arg);
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
	reset_image(data);
	update_progress(data, 0);
	create_threads(data);
	if (join_threads(data) != 0)
		exit_error(data, "Thread error (aborting render)");
	else
		mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
								data->mlx->img, 0, 0);
}

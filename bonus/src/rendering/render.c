/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/18 14:52:57 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	render_tile(t_render_info *info, t_tile *tile)
{
	t_pixel	pixel;
	t_color	color;
	int		color_int;

	if (!info || !tile)
		return (print_error("render_tile", INVALID_POINTER), -1);
	pixel.y = tile->start.y;
	while (pixel.y <= tile->end.y)
	{
		pixel.x = tile->start.x;
		while (pixel.x <= tile->end.x)
		{
			if (render_pixel(&color, info, &pixel) != 0)
				return (print_error("render_strip", THREAD_ERROR));
			color_int = rgb_stoi(color);
			if (color_int != 0)
				set_pixel_color(info->data, pixel.x, pixel.y, color_int);
			pixel.x++;
		}
		pixel.y++;
	}
	return (0);
}

void	render(t_data *data)
{
	t_thread_info	thread_info;

	if (!data)
		return ;
	initialize_render(data, &thread_info);
	multi_thread_render(data, &thread_info);
	handle_any_thread_errors(data, thread_info);
	display_rendered_image(data);
}

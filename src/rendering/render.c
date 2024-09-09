/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 18:29:05 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	generate_image(t_data *data)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;
	int		color_int;

	if (!data)
		return (print_error("generate_image", INVALID_POINTER), 1);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			ray = ray_for_pixel(*(data->camera), x, y);
			if (color_at(&color, &ray, data->world) != 0)
				return (1);
			color_int = rgb_stoi(color);
			if (color_int != 0)
				set_pixel_color(data, x, y, color_int);
			y++;
		}
		x++;
	}
	return (0);
}

void	render(t_data *data)
{
	if (!data)
	{
		print_error("render", INVALID_POINTER);
		return ;
	}
	reset_image(data);
	if (generate_image(data) != 0)
		exit_error(data, "unable to render image: aborting program");
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
							data->mlx->img, 0, 0);
}

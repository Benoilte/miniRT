/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:02:05 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/17 15:48:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	set_px_medium_sample(	t_color *color, \
									t_render_info *info, \
									t_pixel *px)
{
	t_color	tmp_color;
	int		res;

	res = 5;
	*color = rgb_set(0, 0, 0);
	while (res > 0)
	{
		if (set_px_one_sample(&tmp_color, info, px) != 0)
			return (1);
		*color = rgb_add(tmp_color, *color);
		if (res == 5)
		{
			px->x_offset = 0;
			px->x_offset = 0;
		}
		if (res == 4)
			px->x_offset = 1.0;
		else if (res == 3)
			px->y_offset = 1.0;
		else if (res == 2)
			px->x_offset = 0.0;
		res--;
	}
	*color = rgb_divide(*color, 5);
	return (0);
}

int	set_px_one_sample(t_color *color, t_render_info *info, t_pixel *px)
{
	t_ray	ray;

	ray = ray_for_pixel(*(info->data->camera), px);
	if (color_at(color, NULL, &ray, info) != 0)
		return (1);
	return (0);
}

int	render_pixel(t_color *color, t_render_info *info, t_pixel *pixel)
{
	if (info->aa_sample_precision == AA_ONE_SAMPLE)
	{
		pixel->x_offset = 0.5;
		pixel->y_offset = 0.5;
		if (set_px_one_sample(color, info, pixel) != 0)
			return (1);
	}
	else if (info->aa_sample_precision == AA_MEDIUM_SAMPLE)
	{
		pixel->x_offset = 0.5;
		pixel->y_offset = 0.5;
		if (set_px_medium_sample(color, info, pixel) != 0)
			return (2);
	}
	else if (info->aa_sample_precision == AA_ADAPTIVE_SAMPLE)
	{
		if (set_px_adaptive_sample(color, info, pixel) != 0)
			return (3);
	}
	return (0);
}

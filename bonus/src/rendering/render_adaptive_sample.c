/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_adaptive_sample.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:56:14 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/17 12:17:39 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	set_random_sample(	t_color *color, \
								t_render_info *info, \
								t_pixel *px, \
								float offset)
{
	int		i;
	int		j;
	int		sample_pos;

	i = -1;
	sample_pos = 0;
	while (++i < AA_HALF_SAMPLE_SIZE)
	{
		j = -1;
		while (++j < AA_HALF_SAMPLE_SIZE)
		{
			px->x_offset = (i + offset) / AA_HALF_SAMPLE_SIZE;
			px->y_offset = (j + offset) / AA_HALF_SAMPLE_SIZE;
			if (set_px_one_sample(color + sample_pos, info, px) != 0)
				return (1);
			sample_pos++;
		}
	}
	return (0);
}

static t_color	sum_color_sample(t_color *color_sample)
{
	int		i;
	t_color	sum_color;

	i = 0;
	sum_color = rgb_set(0, 0, 0);
	while (i < AA_SAMPLE_SIZE)
		sum_color = rgb_add(sum_color, color_sample[i++]);
	return (sum_color);
}

static float	get_variance(t_color *avg_color, t_color *color_samples)
{
	float	var;
	int		i;

	i = -1;
	var = 0;
	while (++i < AA_SAMPLE_SIZE)
		var += rgb_magnitude_squared(rgb_sub(color_samples[i], *avg_color));
	return (var / AA_SAMPLE_SIZE);
}

static t_color	get_avg_color(	t_color *color, \
								t_color *sampled_color, \
								int iteration)
{
	if (!iteration)
		return (*sampled_color);
	else
		return (rgb_divide(rgb_add(*color, *sampled_color), 2));
}

int	set_px_adaptive_sample(t_color *color, t_render_info *info, t_pixel *px)
{
	t_color	color_samples[AA_SAMPLE_SIZE];
	t_color	tmp_color;
	float	offset;
	int		i;

	offset = 0.2;
	i = 0;
	while (i < AA_DEPTH)
	{
		if (set_random_sample(color_samples, info, px, offset) != 0)
			return (1);
		tmp_color = rgb_divide(sum_color_sample(color_samples), 4);
		*color = get_avg_color(color, &tmp_color, i);
		if (get_variance(color, color_samples) < AA_VARIANCE_TRESHOLD)
			return (0);
		i++;
		offset += 0.2;
	}
	return (0);
}

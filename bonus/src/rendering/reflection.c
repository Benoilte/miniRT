/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:18:57 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 10:30:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	reflected_color(t_color *color, t_render_info info, t_details *details)
{
	t_ray	reflect_ray;

	if (equalf(details->shape->material.reflective, 0)
		|| (info.reflective_depth <= 0))
	{
		*color = rgb_set(0, 0, 0);
		return (0);
	}
	reflect_ray = ray(details->over_point, details->reflectv);
	info.reflective_depth--;
	if (color_at(color, details->shape, &reflect_ray, &info) != 0)
		return (1);
	*color = rgb_scale(*color, details->shape->material.reflective);
	return (0);
}

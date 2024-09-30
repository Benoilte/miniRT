/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:18:57 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/30 16:50:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	reflected_color(t_color *color, t_world *world, t_details *details)
{
	t_ray	reflect_ray;

	if (equalf(details->shape->material.reflective, 0)
		|| (world->reflective_depth <= 0))
	{
		*color = rgb_set(0, 0, 0);
		return (0);
	}
	reflect_ray = ray(details->over_point, details->reflectv);
	world->reflective_depth--;
	if (color_at(color, &reflect_ray, world) != 0)
		return (1);
	*color = rgb_scale(*color, details->shape->material.reflective);
	return (0);
}

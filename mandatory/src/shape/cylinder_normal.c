/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/12 16:36:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

// take the object_point and remove the y component.

static bool	hit_upper_cap(t_shape *shape, t_point *object_point, float dist)
{
	float	max;

	max = shape->cylinder.max - EPSILON;
	return ((dist < 1) && greater_or_equalf(object_point->y, max));
}

static bool	hit_lower_cap(t_shape *shape, t_point *object_point, float dist)
{
	float	min;

	min = shape->cylinder.min + EPSILON;
	return ((dist < 1) && lower_or_equalf(object_point->y, min));
}

t_vector	normal_cylinder(t_shape *shape, t_point *object_point)
{
	float	dist;

	dist = fsquaref(object_point->x) + fsquaref(object_point->z);
	if (shape->cylinder.closed && hit_upper_cap(shape, object_point, dist))
		return (vector(0, 1, 0));
	else if (shape->cylinder.closed && hit_lower_cap(shape, object_point, dist))
		return (vector(0, -1, 0));
	else
		return (vector(object_point->x, 0, object_point->z));
}

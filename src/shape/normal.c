/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:53:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/30 17:02:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

static t_point	get_object_point(t_m4x4 *inverted, t_point *world_point)
{
	return (mx_mult_tuple(*inverted, *world_point));
}

static t_vector	get_world_normal(t_m4x4 *inverted, t_vector *object_normal)
{
	t_vector	world_normal;

	world_normal = mx_mult_tuple(mx_transpose(*inverted), *object_normal);
	world_normal.w = VECTOR;
	return (tp_normalize(world_normal));
}

t_vector	get_normal(t_shape *shape, t_point world_point)
{
	t_point		object_point;
	t_vector	object_normal;

	object_point = get_object_point(&shape->inverse, &world_point);
	object_normal = shape->f->normal(shape, &object_point);
	return (get_world_normal(&shape->inverse, &object_normal));
}

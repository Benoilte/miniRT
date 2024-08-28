/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:53:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/28 21:50:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

static t_point	get_object_point(t_m4x4 *inverted, t_point *world_point)
{
	return (mx_mult_tuple(*inverted, *world_point));
}

// static t_vector	get_object_normal(t_point *object_point)
// {
// 	t_point	origin;

// 	origin = point(0, 0, 0);
// 	return (tp_normalize(tp_subtract(*object_point, origin)));
// }

static t_vector	get_world_normal(t_m4x4 *inverted, t_vector *object_normal)
{
	t_vector	world_normal;

	world_normal = mx_mult_tuple(mx_transpose(*inverted), *object_normal);
	world_normal.w = 0;
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

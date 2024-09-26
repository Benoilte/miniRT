/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:53:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/17 14:55:09 by bgolding         ###   ########.fr       */
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

t_m4x4	rotate_y_to(t_vector to)
{
	const t_vector	y = (t_vector){0, 1, 0, VECTOR};
	const float		dot = tp_dot_product(y, to);
	const float		k = 1.0f / (1.0f + dot);
	t_vector		r;

	if (equalf(dot, -1))
		return (mx_reflection(X_AXIS));
	r = tp_cross_product(y, to);
	return ((t_m4x4){{\
	{(r.x * r.x * k) + dot, (r.y * r.x * k) - r.z, (r.z * r.x * k) + r.y, 0}, \
	{(r.x * r.y * k) + r.z, (r.y * r.y * k) + dot, (r.z * r.y * k) - r.x, 0}, \
	{(r.x * r.z * k) - r.y, (r.y * r.z * k) + r.x, (r.z * r.z * k) + dot, 0}, \
	{0, 0, 0, 1}}});
}

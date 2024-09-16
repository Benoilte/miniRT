/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:28:47 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/16 18:36:04 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	set_default_plane(t_shape *self)
{
	self->center = point(PLANE_DEFAULT_X, PLANE_DEFAULT_Y, PLANE_DEFAULT_Z);
	self->transform = mx_identity();
	self->inverse = mx_identity();
}

const t_vtable	*get_plane_vtable(void)
{
	static const t_vtable	plane_vtable = {\
		set_default_plane, destroy_shape, intersect_plane, normal_plane};

	return (&plane_vtable);
}

t_m4x4	get_rot(t_vector a, t_vector b);

int	set_plane(t_shape *self, char **args)
{
	t_point		origin;
	t_vector	normal;

	if (!self || !args)
		return (print_error("set_plane", INVALID_POINTER));
	origin = str_to_tuple(args[1], POINT);
	normal = tp_normalize(str_to_tuple(args[2], VECTOR));
	self->transform = get_rot(vector(0, 1, 0), normal);
	self->transform = mx_add_translation(self->transform, \
											origin.x, origin.y, origin.z);
	self->inverse = mx_inversion(self->transform);
	self->material.color = str_to_rgb(args[3]);
	return (0);
}

t_m4x4	get_rot(t_vector a, t_vector b)
{
	t_vector	r;
	const float	dot = tp_dot_product(a, b);
	const float	k = 1.0f / (1.0f + dot);

	printf("dot(a . b): %f\n", dot);
	if (equalf(dot, -1))
		return (mx_reflection(Y_AXIS));
	r = tp_cross_product(a, b);
	return ((t_m4x4){{\
		{(r.x * r.x * k) + dot, (r.y * r.x * k) - r.z, (r.z * r.x * k) + r.y, 0}, \
		{(r.x * r.y * k) + r.z, (r.y * r.y * k) + dot, (r.z * r.y * k) - r.x, 0}, \
		{(r.x * r.z * k) - r.y, (r.y * r.z * k) + r.x, (r.z * r.x * k) + dot, 0}, \
		{0, 0, 0, 1}}});
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:28:47 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/17 14:56:38 by bgolding         ###   ########.fr       */
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

int	set_plane(t_shape *self, char **args)
{
	t_point		origin;
	t_vector	normal;

	if (!self || !args)
		return (print_error("set_plane", INVALID_POINTER));
	origin = str_to_tuple(args[1], POINT);
	normal = tp_normalize(str_to_tuple(args[2], VECTOR));
	self->transform = rotate_y_to(normal);
	self->transform = mx_add_translation(self->transform, \
											origin.x, origin.y, origin.z);
	self->inverse = mx_inversion(self->transform);
	self->material.color = str_to_rgb(args[3]);
	return (0);
}

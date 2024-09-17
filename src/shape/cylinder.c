/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/17 15:38:58 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	set_default_cylinder(t_shape *self)
{
	self->center = point(CL_DEFAULT_X, CL_DEFAULT_Y, CL_DEFAULT_Z);
	self->cylinder.min = -1;
	self->cylinder.max = 1;
	self->cylinder.closed = true;
	self->transform = mx_identity();
	self->inverse = mx_identity();
}

const t_vtable	*get_cylinder_vtable(void)
{
	static const t_vtable	cylinder_vtable = {\
		set_default_cylinder, set_cylinder, destroy_shape, \
		intersect_cylinder, normal_cylinder};

	return (&cylinder_vtable);
}

int	set_cylinder(t_shape *self, char **args)
{
	t_point		origin;
	t_vector	normal;
	float		radius;

	if (!self || !args)
		return (print_error("set_cylinder", INVALID_POINTER));
	origin = str_to_tuple(args[1], POINT);
	normal = tp_normalize(str_to_tuple(args[2], VECTOR));
	radius = ft_atod(args[3]) / 2;
	self->transform = mx_add_scaling(self->transform, \
										radius, ft_atod(args[4]) / 2, radius);
	self->transform = mx_mult(rotate_y_to(normal), self->transform);
	self->transform = mx_add_translation(self->transform, \
											origin.x, origin.y, origin.z);
	self->inverse = mx_inversion(self->transform);
	self->material.color = str_to_rgb(args[5]);
	return (0);
}

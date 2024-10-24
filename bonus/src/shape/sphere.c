/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:31:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 15:50:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_default_sphere(t_shape *self)
{
	self->center = point(SPHERE_DEFAULT_X, SPHERE_DEFAULT_Y, SPHERE_DEFAULT_Z);
	self->sphere.radius = SPHERE_DEFAULT_RADIUS;
	self->sphere.sq_radius = fsquaref(SPHERE_DEFAULT_RADIUS);
	self->transform = mx_identity();
	self->inverse = mx_identity();
}

const t_vtable	*get_sphere_vtable(void)
{
	static const t_vtable	sphere_vtable = {set_default_sphere, set_sphere, \
	destroy_shape, intersect_sphere, normal_sphere, move_shape_origin};

	return (&sphere_vtable);
}

int	set_sphere(t_shape *self, char **args, t_world *world)
{
	t_point	origin;
	float	radius;

	if (!self || !args || !world)
		return (print_error("set_sphere", INVALID_POINTER));
	origin = str_to_tuple(args[1], POINT);
	radius = rt_roundf(ft_atod(args[2]) / 2);
	self->transform = mx_add_scaling(self->transform, radius, radius, radius);
	self->transform = mx_add_translation(self->transform, \
											origin.x, origin.y, origin.z);
	self->inverse = mx_inversion(self->transform);
	self->material = world->default_material;
	self->material.color = str_to_rgb(args[3]);
	self->material.ambient = rgb_mult(self->material.color, world->ambient);
	if (args[4])
		set_shape_bonus(self, &args[4]);
	return (0);
}

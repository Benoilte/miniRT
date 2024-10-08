/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:42:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 21:45:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_default_cube(t_shape *self)
{
	self->center = point(CU_DEFAULT_X, CU_DEFAULT_Y, CU_DEFAULT_Z);
	self->transform = mx_identity();
	self->inverse = mx_identity();
}

const t_vtable	*get_cube_vtable(void)
{
	static const t_vtable	cube_vtable = {\
		set_default_cube, set_cube, destroy_shape, \
		intersect_cube, normal_cube};

	return (&cube_vtable);
}

int	set_cube(t_shape *self, char **args, t_world *world)
{
	t_point		origin;
	t_vector	normal;
	float		radius;

	if (!self || !args || !world)
		return (print_error("set_cube", INVALID_POINTER));
	origin = str_to_tuple(args[1], POINT);
	normal = tp_normalize(str_to_tuple(args[2], VECTOR));
	radius = rt_roundf(ft_atod(args[3]) / 2);
	self->transform = mx_add_scaling(self->transform, radius, \
									rt_roundf(ft_atod(args[4]) / 2), radius);
	self->transform = mx_mult(rotate_y_to(normal), self->transform);
	self->transform = mx_add_translation(self->transform, \
											origin.x, origin.y, origin.z);
	self->inverse = mx_inversion(self->transform);
	self->material = world->default_material;
	self->material.color = str_to_rgb(args[5]);
	self->material.ambient = rgb_mult(self->material.color, world->ambient);
	if (args[6])
		set_shape_bonus(self, &(args[6]));
	return (0);
}

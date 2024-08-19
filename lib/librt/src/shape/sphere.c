/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:31:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/19 15:32:43 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	set_default_sphere(t_shape *self)
{
	self->center = point(SPHERE_DEFAULT_X, SPHERE_DEFAULT_Y, SPHERE_DEFAULT_Z);
	self->color = (t_color) \
		{SPHERE_DEFAULT_RED, SPHERE_DEFAULT_GREEN, SPHERE_DEFAULT_BLUE};
	self->sphere.radius = SPHERE_DEFAULT_RADIUS;
	self->sphere.sq_radius = fsquaref(SPHERE_DEFAULT_RADIUS);
	self->transform = mx_identity();
}

const t_shape_vtable	*get_sphere_vtable(void)
{
	static const t_shape_vtable	sphere_vtable = {\
		set_default_sphere, destroy_shape};

	return (&sphere_vtable);
}

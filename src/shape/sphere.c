/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:31:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/06 16:46:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

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
	static const t_vtable	sphere_vtable = {\
		set_default_sphere, destroy_shape, intersect_sphere, normal_sphere};

	return (&sphere_vtable);
}

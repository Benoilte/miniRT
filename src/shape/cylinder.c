/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 08:11:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	set_default_cylinder(t_shape *self)
{
	self->center = point(CL_DEFAULT_X, CL_DEFAULT_Y, CL_DEFAULT_Z);
	self->cylinder.min = -1;
	self->cylinder.max = 1;
	self->transform = mx_identity();
	self->inverse = mx_identity();
}

const t_vtable	*get_cylinder_vtable(void)
{
	static const t_vtable	cylinder_vtable = {\
		set_default_cylinder, destroy_shape, \
		intersect_cylinder, normal_cylinder};

	return (&cylinder_vtable);
}

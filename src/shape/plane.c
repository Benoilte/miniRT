/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:28:47 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/09 18:31:03 by bgolding         ###   ########.fr       */
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

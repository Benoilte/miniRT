/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:42:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 14:15:47 by bebrandt         ###   ########.fr       */
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
	(void)self;
	(void)args;
	(void)world;
	return (0);
}

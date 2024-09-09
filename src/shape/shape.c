/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:54:15 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 14:28:29 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	invalid_shape_type(t_shape_type type)
{
	if (type < 0 || type >= SHAPE_COUNT)
		return (true);
	return (false);
}

void	destroy_shape(void *self)
{
	t_shape	*shape;

	if (!self)
		return (shape_error("destroy_shape", SH_INVALID_POINTER));
	shape = (t_shape *)self;
	free(shape);
	return ;
}

int	set_shape_vtable(t_shape *new, t_shape_type type)
{
	if (!new)
		return (shape_error("set_shape_vtable", SH_INVALID_POINTER), 1);
	if (invalid_shape_type(type))
		return (shape_error("set_shape_vtable", SH_INVALID_TYPE), 2);
	if (type == SPHERE)
		new->f = get_sphere_vtable();
	if (type == PLANE)
		new->f = get_plane_vtable();
	return (0);
}

t_shape	*create_new_shape(t_shape_type type)
{
	t_shape	*new;

	if (invalid_shape_type(type))
		return (shape_error("create_new_shape", SH_INVALID_TYPE), NULL);
	new = malloc(sizeof(t_shape));
	if (!new)
		return (perror("create_new_shape"), NULL);
	new->type = type;
	if (set_shape_vtable(new, type) != 0)
	{
		shape_error("create_new_shape", SH_VTABLE_ERROR);
		free(new);
		return (NULL);
	}
	new->f->set_default_shape(new);
	set_default_material(&new->material);
	return (new);
}

void	update_inverse(t_shape *shape)
{
	if (!shape)
		return (shape_error("update_inverse", SH_INVALID_POINTER));
	shape->inverse = mx_inversion(shape->transform);
}

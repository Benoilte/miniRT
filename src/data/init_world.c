/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:49:42 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/27 15:40:36 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	*init_world(void)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	if (!world)
		return (NULL);
	return (world);
}

int	add_new_shape_to_world(t_world *world, t_shape_type type)
{
	t_shape			*new_shape;
	t_shape_list	*new_node;

	if (!world || invalid_shape_type(type))
		return (1);
	new_shape = create_new_shape(type);
	if (!new_shape)
		return (2);
	new_node = ft_lstnew(new_shape);
	if (!new_node)
	{
		destroy_shape(new_shape);
		return (3);
	}
	ft_lstadd_back(&world->shapes, new_node);
	return (0);
}

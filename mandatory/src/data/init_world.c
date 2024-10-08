/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:49:42 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/27 17:04:32 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	*init_world(t_list *token_list)
{
	t_world	*world;
	char	**element;

	world = ft_calloc(1, sizeof(t_world));
	if (!world)
		return (NULL);
	element = get_element(token_list, ID_LIGHT);
	world->light = init_light(element);
	if (!world->light)
		return (destroy_world(world), NULL);
	element = get_element(token_list, ID_AMBIENT);
	world->ambient = get_ambient(element);
	if (init_shapes(world, token_list) != 0)
		return (destroy_world(world), NULL);
	return (world);
}

t_shape	*add_new_shape_to_world(t_world *world, t_shape_type type)
{
	t_shape			*new_shape;
	t_shape_list	*new_node;

	if (!world)
		return (shape_error("add_new_shape_to_world", INVALID_POINTER), NULL);
	if (invalid_shape_type(type))
		return (shape_error("add_new_shape_to_world", SH_INVALID_TYPE), NULL);
	new_shape = create_new_shape(type);
	if (!new_shape)
		return (shape_error("add_new_shape_to_world", strerror(errno)), NULL);
	new_node = ft_lstnew(new_shape);
	if (!new_node)
	{
		destroy_shape(new_shape);
		return (shape_error("add_new_shape_to_world", strerror(errno)), NULL);
	}
	ft_lstadd_back(&world->shapes, new_node);
	return (new_shape);
}

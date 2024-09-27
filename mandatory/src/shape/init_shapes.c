/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:17:34 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/27 16:55:28 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_shape(t_id id)
{
	return (ID_SPHERE <= id && id < ID_VALID_COUNT);
}

t_list	*get_next_shape(t_list *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens)
	{
		if (is_shape((((t_token *)tokens->content)->identifier)))
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

static t_shape_type	get_type(t_id id)
{
	return (id - ID_SPHERE);
}

int	init_shapes(t_world *world, t_list *token_list)
{
	t_list	*shape_token;
	t_token	*token;
	t_shape	*new_shape;

	shape_token = get_next_shape(token_list);
	if (!shape_token)
		return (print_error("init_shapes", "no shapes in list"));
	while (shape_token)
	{
		token = (t_token *)shape_token->content;
		new_shape = add_new_shape_to_world(world, get_type(token->identifier));
		if (!new_shape)
			return (1);
		new_shape->f->set(new_shape, token->args, world->ambient);
		shape_token = get_next_shape(shape_token->next);
	}
	return (0);
}

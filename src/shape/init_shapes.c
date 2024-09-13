/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:17:34 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/13 17:25:41 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_shape(t_id id)
{
	return (ID_SPHERE <= id && id < ID_VALID_COUNT);
}

static t_list	*get_next_shape(t_list *tokens)
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
	/*
		Iterate over tokens
			if shape
				add_new_shape_to_world[type]
				set_shape[type] << const function array
	*/
	t_list	*shape_token;
	t_shape	*new_shape;

	shape_token = get_next_shape(token_list);
	while (shape_token)
	{
		(void)new_shape;
		(void)world;
		ft_printf("Placeholder for add_new_shape_to_world(%d)\n", get_type(((t_token *)shape_token->content)->identifier));
		shape_token = get_next_shape(shape_token->next);
	}
	return (0);
}

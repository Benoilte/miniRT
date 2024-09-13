/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:17:34 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/13 15:34:34 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_shape(t_id id)
{
	return (ID_SPHERE <= id && id < ID_VALID_COUNT);
}

static t_token	*get_next_shape(t_list *token_list)
{
	t_token	*token;

	if (!token_list)
		return (NULL);
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (is_shape(token->identifier))
			return (token);
		token_list = token_list->next;
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
	t_token	*token;
	t_shape	*new_shape;

	while (token_list)
	{
		token = get_next_shape(token_list);
		(void)new_shape;
		(void)world;
		ft_printf("Placeholder for add_new_shape_to_world(%d)\n", get_type(token->identifier));
		token_list = token_list->next;
	}
	return (0);
}

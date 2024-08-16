/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:54:15 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/16 17:33:45 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	invalid_shape_type(t_shape_type type)
{
	if (type < 0 || type >= SHAPE_COUNT)
		return (true);
	return (false);
}

void	destroy_shape(t_shape *self)
{
	return ;
}

t_shape	*create_new_shape(t_shape_type type)
{
	t_shape	*new;

	if (invalid_shape_type(type))
		return (shape_error("create_new_shape", SH_INVALID_ERROR), NULL);
	new = malloc(sizeof(t_shape));
	if (!new)
		return (perror("create_new_shape"), NULL);
	else
	{
		new->type = type;
		new->f = 
	}
	return (new);
}

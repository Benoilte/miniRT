/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiling.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:43:13 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/16 16:14:22 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_tile(void *content)
{
	if (content)
		free(content);
}

static t_tile	*init_tile(t_pixel start)
{
	t_tile	*tile;

	tile = ft_calloc(1, sizeof(t_tile));
	if (!tile)
	{
		print_error("init_tile_node", strerror(errno));
		return (NULL);
	}
	tile->start.x = start.x;
	tile->start.y = start.y;
	tile->end.x = start.x + TILE_WIDTH - 1;
	tile->end.y = start.y + TILE_HEIGHT - 1;
	return (tile);
}

static t_list	*init_tile_node(t_pixel start)
{
	t_list	*tile_node;
	t_tile	*tile;

	tile = init_tile(start);
	if (!tile)
		return (NULL);
	tile_node = ft_lstnew(tile);
	if (!tile_node)
	{
		print_error("ft_lstnew", strerror(errno));
		destroy_tile(tile);
		return (NULL);
	}
	return (tile_node);
}

int	init_tile_stack(t_list **tile_stack, t_pixel end)
{
	t_pixel	start;
	t_list	*tile_node;

	if (!tile_stack)
		return (print_error("init_tile_stack", INVALID_POINTER));
	start.y = end.y - TILE_HEIGHT + 1;
	while (start.y >= 0)
	{
		start.x = end.x - TILE_WIDTH + 1;
		while (start.x >= 0)
		{
			tile_node = init_tile_node(start);
			if (!tile_node)
				return (ft_lstclear(tile_stack, destroy_tile), 1);
			ft_lstadd_front(tile_stack, tile_node);
			start.x -= TILE_WIDTH;
		}
		start.y -= TILE_HEIGHT;
	}
	return (0);
}

t_tile	*get_next_tile(t_list **tile_stack)
{
	t_tile	*tile;
	t_list	*tile_node;

	tile_stack_mutex(MTX_LOCK);
	tile_node = ft_lstpop_top(tile_stack);
	tile_stack_mutex(MTX_UNLOCK);
	if (!tile_node)
		return (NULL);
	tile = (t_tile *)tile_node->content;
	tile_node->content = NULL;
	free(tile_node);
	return (tile);
}

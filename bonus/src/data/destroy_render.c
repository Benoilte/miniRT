/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:56:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/16 15:37:45 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	destroy_all_mutexes(void)
{
	if (print_mutex(MTX_DESTROY) != 0)
		print_error("destroy_all_mutexes", PRINT_MUTEX_DEST_ERR);
	if (tile_stack_mutex(MTX_DESTROY) != 0)
		print_error("destroy_all_mutexes", TILE_MUTEX_DEST_ERR);
}

static void	destroy_render_blocks(t_render *render)
{
	int	i;

	if (!render)
		return ;
	i = 0;
	while (i < render->thread_count)
		destroy_shape_container(&render->blocks[i++].shape_container);
	free(render->blocks);
	render->blocks = NULL;
}

void	destroy_render_settings(t_render *render)
{
	if (!render)
		return ;
	if (render->blocks)
		destroy_render_blocks(render);
	if (render->threads)
	{
		free(render->threads);
		render->threads = NULL;
	}
	if (render->tile_stack)
		ft_lstclear(&render->tile_stack, destroy_tile);
	destroy_all_mutexes();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:55:02 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 12:47:01 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	init_render_blocks(t_data *data, t_render *render)
{
	int	slice_size;
	int	i;

	if (WIN_HEIGHT % render->thread_count != 0)
		ft_printf("Warning: WIN_HEIGHT not optimal for multi-thread rendering");
	slice_size = WIN_HEIGHT / render->thread_count;
	render->blocks = ft_calloc(render->thread_count, sizeof(t_render_info));
	if (!render->blocks)
		return (1);
	i = 0;
	while (i < render->thread_count)
	{
		render->blocks[i].thread_id = i;
		render->blocks[i].data = data;
		render->blocks[i].start_line = i * slice_size;
		render->blocks[i].stop_line = render->blocks[i].start_line + slice_size;
		render->blocks[i].reflective_depth = REFLECTIVE_DEPTH;
		render->blocks[i].refractive_depth = REFRACTIVE_DEPTH;
		if (init_shape_container(ft_lstsize(data->world->shapes), \
			&(render->blocks[i].shape_container)) != 0)
			return (1);
		i ++;
	}
	return (0);
}

int	init_render_settings(t_data *data, t_render *render)
{
	render->thread_count = get_available_core_count();
	render->threads = ft_calloc(render->thread_count, sizeof(pthread_t));
	if (!render->threads)
		return (1);
	if (init_render_blocks(data, render) != 0)
		return (2);
	pthread_mutex_init(&render->print_lock, NULL);
	return (0);
}

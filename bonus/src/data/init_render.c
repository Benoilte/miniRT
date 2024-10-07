/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:55:02 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 12:12:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_render_settings(t_data *data, t_render *render)
{
	int	slice_size;
	int	i;

	render->thread_count = get_available_core_count();
	if (WIN_HEIGHT % render->thread_count != 0)
		ft_printf("Warning: WIN_HEIGHT not optimal for multi-thread rendering");
	slice_size = WIN_HEIGHT / render->thread_count;
	render->blocks = ft_calloc(render->thread_count, sizeof(t_render_info));
	if (!render->blocks)
		return (1);
	render->threads = ft_calloc(render->thread_count, sizeof(pthread_t));
	if (!render->threads)
		return (2);
	i = 0;
	while (i < render->thread_count)
	{
		render->blocks[i].thread_id = i;
		render->blocks[i].data = data;
		render->blocks[i].start_line = i * slice_size;
		render->blocks[i].stop_line = render->blocks[i].start_line + slice_size;
		render->blocks[i].reflective_depth = REFLECTIVE_DEPTH;
		data->render[i].refractive_depth = REFRACTIVE_DEPTH;
		if (init_shape_container(ft_lstsize(data->world->shapes), \
			&(data->render[i].shape_container)) != 0)
			return (1);
		i ++;
	}
	pthread_mutex_init(&render->print_lock, NULL);
	return (0);
}

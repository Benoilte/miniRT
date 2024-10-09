/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:55:02 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/09 16:13:15 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_render_depth(t_render *render, char **element)
{
	if (element && count_args((const char **)element) == DEPTH_PARAMS + 1)
	{
		render->master_reflective_depth = ft_atoi(element[1]);
		render->master_refractive_depth = ft_atoi(element[2]);
	}
	else
	{
		render->master_reflective_depth = DEFAULT_REFLECTIVE_DEPTH;
		render->master_refractive_depth = DEFAULT_REFRACTIVE_DEPTH;
	}
	ft_printf("Reflective depth set to: %d\n", render->master_reflective_depth);
	ft_printf("Refractive depth set to: %d\n", render->master_refractive_depth);
}

static int	init_render_blocks(t_data *data, t_render *render)
{
	int	slice_size;
	int	i;

	if (data->resolution.y % render->thread_count != 0)
		ft_putendl_fd(RES_RENDER_WARN, STDERR_FILENO);
	slice_size = data->resolution.y / render->thread_count;
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
		render->blocks[i].reflective_depth = render->master_reflective_depth;
		render->blocks[i].refractive_depth = render->master_refractive_depth;
		if (init_shape_container(ft_lstsize(data->world->shapes), \
			&(render->blocks[i].shape_container)) != 0)
			return (1);
		i ++;
	}
	render->blocks[i - 1].stop_line = data->resolution.y;
	return (0);
}

int	init_render_settings(t_data *data, t_render *render)
{
	render->thread_count = get_available_core_count();
	render->threads = ft_calloc(render->thread_count, sizeof(pthread_t));
	if (!render->threads)
		return (1);
	set_render_depth(render, get_element(data->input.token_list, ID_DEPTH));
	if (init_render_blocks(data, render) != 0)
		return (2);
	return (0);
}

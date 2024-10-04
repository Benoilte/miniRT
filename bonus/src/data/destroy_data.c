/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:05:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/04 00:15:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	destroy_render_info(t_data *data)
{
	int	i;

	i = 0;
	while (i < THREAD_COUNT)
		destroy_shape_container(&data->render[i++].shape_container);
}

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	destroy_input(&data->input);
	destroy_mlx(data->mlx);
	destroy_world(data->world);
	destroy_camera(data->camera);
	destroy_render_info(data);
	pthread_mutex_destroy(&data->print_lock);
	free(data);
}

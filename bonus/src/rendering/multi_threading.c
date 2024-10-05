/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:05:11 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/05 16:05:32 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->render.thread_count)
	{
		if (pthread_create(&data->render.threads[i], NULL, render_strip, \
							&data->render.blocks[i]))
			exit_error(data, "pthread creation error");
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->render.thread_count)
		if (pthread_join(data->render.threads[i++], NULL))
			exit_error(data, "pthread join error");
}

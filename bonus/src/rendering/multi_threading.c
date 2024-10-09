/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:05:11 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/09 16:08:44 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_threads(t_data *data)
{
	int	i;

	if (print_mutex(PRINT_MTX_INIT) != 0)
		exit_error(data, "Unable to initialize print_error mutex");
	i = 0;
	while (i < data->render.thread_count)
	{
		if (pthread_create(&data->render.threads[i], NULL, render_strip, \
							&data->render.blocks[i]))
			exit_error(data, "pthread creation error");
		i++;
	}
}

int	join_threads(t_data *data)
{
	int		i;
	void	*ret;
	int		thread_error_count;

	thread_error_count = 0;
	i = 0;
	while (i < data->render.thread_count)
	{
		if (pthread_join(data->render.threads[i++], &ret))
			exit_error(data, "pthread join error");
		if (ret)
		{
			thread_error_count++;
			ret = NULL;
		}
	}
	if (print_mutex(PRINT_MTX_DESTROY) != 0)
		exit_error(data, "Unable to destroy print_error mutex");
	return (thread_error_count);
}

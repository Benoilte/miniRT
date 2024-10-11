/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:05:11 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/11 16:53:36 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_threads(t_data *data)
{
	int	i;
	int	threads_created;

	data->errlog = freopen(ERR_LOG_FILE, "w", stderr);
	if (!data->errlog)
		exit_error(data, REDIR_STDERR_ERR);
	if (print_mutex(PRINT_MTX_INIT) != 0)
		exit_error(data, PRINT_MUTEX_INIT_ERR);
	i = 0;
	threads_created = 0;
	while (i < data->render.thread_count)
	{
		if (pthread_create(&data->render.threads[i], NULL, render_strip, \
							&data->render.blocks[i]))
			print_error("create_threads", strerror(errno));
		else
			threads_created++;
		i++;
	}
	return (threads_created);
}

int	join_threads(t_data *data)
{
	int		i;
	int		join_result;
	void	*ret;
	int		thread_error_count;

	thread_error_count = 0;
	i = 0;
	while (i < data->render.thread_count)
	{
		join_result = pthread_join(data->render.threads[i++], &ret);
		if (join_result)
			print_error("join_threads", strerror(join_result));
		else if (ret == (void *)1)
			thread_error_count++;
	}
	if (print_mutex(PRINT_MTX_DESTROY) != 0)
		print_error("join_threads", PRINT_MUTEX_DEST_ERR);
	return (thread_error_count);
}

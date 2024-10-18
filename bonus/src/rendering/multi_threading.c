/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:05:11 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/18 14:55:22 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	multi_thread_render(t_data *data, t_thread_info *thread_info)
{
	thread_info->count = data->render.thread_count;
	if (redirect_stderr_to_log_file(data) != 0)
		exit_error(data, REDIR_STDERR_ERR);
	thread_info->created = create_threads(data);
	if (!thread_info->created)
		exit_error(data, NO_THREAD_ERROR);
	thread_info->errors = join_threads(data);
	if (restore_stderr(data) != 0)
		exit_error(data, RESTORE_STDERR_ERR);
}

void	*thread_render_routine(void *arg)
{
	t_render_info	*info;
	t_tile			*tile;

	info = (t_render_info *)arg;
	tile = get_next_tile(&info->data->render.tile_stack);
	while (tile)
	{
		if (render_tile(info, tile) != 0)
			return (destroy_tile(tile), (void *)1);
		destroy_tile(tile);
		update_progress(info->data, 1);
		tile = get_next_tile(&info->data->render.tile_stack);
	}
	return ((void *)0);
}

int	create_threads(t_data *data)
{
	int	i;
	int	threads_created;

	i = 0;
	threads_created = 0;
	while (i < data->render.thread_count)
	{
		if (pthread_create(&data->render.threads[i], NULL, \
							thread_render_routine, &data->render.blocks[i]))
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
	return (thread_error_count);
}

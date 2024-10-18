/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:05:11 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/18 12:23:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	redirect_stderr_to_log_file(t_data *data)
{
	data->errlog_fd = open(ERR_LOG_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->errlog_fd == -1)
		return (perror(ERR_LOG_FILE), 1);
	data->stderr_cpy = dup(STDERR_FILENO);
	if (data->stderr_cpy == 2)
		return (perror("dup"), -1);
	if (dup2(data->errlog_fd, STDERR_FILENO) == -1)
		return (perror("dup2"), 3);
	return (0);
}

int	create_threads(t_data *data)
{
	int	i;
	int	threads_created;

	if (redirect_stderr_to_log_file(data) != 0)
		exit_error(data, REDIR_STDERR_ERR);
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
	return (thread_error_count);
}

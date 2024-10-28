/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:22:21 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/16 16:19:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	report_threads_created(int created, int total)
{
	if (print_mutex(MTX_LOCK) != 0)
		return (-1);
	ft_putstr_fd("Threads created: ", STDERR_FILENO);
	ft_putnbr_fd(created, STDERR_FILENO);
	ft_putchar_fd('/', STDERR_FILENO);
	ft_putnbr_fd(total, STDERR_FILENO);
	ft_putendl_fd("", STDERR_FILENO);
	if (print_mutex(MTX_UNLOCK) != 0)
		return (-1);
	return (0);
}

int	report_threads_failed(int thread_error_count)
{
	if (print_mutex(MTX_LOCK) != 0)
		return (-1);
	ft_putstr_fd("Threads aborted: ", STDERR_FILENO);
	ft_putnbr_fd(thread_error_count, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	if (print_mutex(MTX_UNLOCK) != 0)
		return (-1);
	return (0);
}

int	handle_any_thread_errors(t_data *data, t_thread_info thread)
{
	if (thread.created != thread.count || thread.errors)
		report_threads_created(thread.created, thread.count);
	if (thread.errors)
	{
		report_threads_failed(thread.errors);
		exit_error(data, INCOMPLETE_RENDER);
	}
	return (0);
}

int	get_available_core_count(void)
{
	const int	default_cores = DEFAULT_THREAD_COUNT;
	int			online_cores;

	online_cores = sysconf(_SC_NPROCESSORS_ONLN);
	if (online_cores == -1)
	{
		perror("sysconf");
		ft_putendl_fd(CORE_COUNT_ERROR, STDERR_FILENO);
		return (default_cores);
	}
	else
		ft_printf("Online CPU cores detected: %d\n", online_cores);
	return (online_cores);
}

int	tile_stack_mutex(t_mutex_type type)
{
	static bool				mutex_active = false;
	static pthread_mutex_t	tile_mutex;

	if (type < 0 || type >= MTX_LIMIT)
		return (-1);
	if (type == MTX_INIT && !mutex_active)
	{
		if (pthread_mutex_init(&tile_mutex, NULL))
			return (1);
		mutex_active = true;
	}
	else if (type == MTX_DESTROY && mutex_active)
	{
		if (pthread_mutex_destroy(&tile_mutex))
			return (2);
		mutex_active = false;
	}
	else if (mutex_active)
	{
		if (type == MTX_LOCK && pthread_mutex_lock(&tile_mutex))
			return (3);
		if (type == MTX_UNLOCK && pthread_mutex_unlock(&tile_mutex))
			return (4);
	}
	return (0);
}

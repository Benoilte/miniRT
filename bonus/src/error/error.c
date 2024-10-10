/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:49:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/10 19:26:36 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	print_mutex(t_mutex_type type)
{
	static bool				mutex_active = false;
	static pthread_mutex_t	print_mutex;

	if (type < 0 || type >= PRINT_MTX_LIMIT)
		return (-1);
	if (type == PRINT_MTX_INIT)
	{
		if (pthread_mutex_init(&print_mutex, NULL))
			return (1);
		mutex_active = true;
	}
	else if (type == PRINT_MTX_DESTROY)
	{
		if (pthread_mutex_destroy(&print_mutex))
			return (2);
		mutex_active = false;
	}
	else if (mutex_active)
	{
		if (type == PRINT_MTX_LOCK && pthread_mutex_lock(&print_mutex))
			return (3);
		if (type == PRINT_MTX_UNLOCK && pthread_mutex_unlock(&print_mutex))
			return (4);
	}
	return (0);
}

int	print_error(const char *source, const char *msg)
{
	if (print_mutex(PRINT_MTX_LOCK) != 0)
		return (-1);
	ft_putendl_fd("Error", STDERR_FILENO);
	if (source)
	{
		ft_putstr_fd((char *)source, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putstr_fd((char *)msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	if (print_mutex(PRINT_MTX_UNLOCK) != 0)
		return (-1);
	return (1);
}

void	exit_error(t_data *data, char *message)
{
	if (message)
	{
		if (errno)
			perror(message);
		else
			ft_putendl_fd(message, STDERR_FILENO);
	}
	printf("\n%s\n%s\n", message, EXIT_ERR_MSG);
	destroy_data(data);
	exit(EXIT_FAILURE);
}

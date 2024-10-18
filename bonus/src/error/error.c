/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:49:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/18 11:59:33 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_timestamp(void)
{
	char		buffer[100];
	time_t		temp;
	struct tm	*timeptr;

	temp = time(NULL);
	timeptr = localtime(&temp);
	strftime(buffer, sizeof(buffer), "[ %d/%m/%y | %T ] ", timeptr);
	ft_putstr_fd(buffer, STDERR_FILENO);
}

int	print_mutex(t_mutex_type type)
{
	static bool				mutex_active = false;
	static pthread_mutex_t	print_mutex;

	if (type < 0 || type >= MTX_LIMIT)
		return (-1);
	if (type == MTX_INIT && !mutex_active)
	{
		if (pthread_mutex_init(&print_mutex, NULL))
			return (1);
		mutex_active = true;
	}
	else if (type == MTX_DESTROY && mutex_active)
	{
		if (pthread_mutex_destroy(&print_mutex))
			return (2);
		mutex_active = false;
	}
	else if (mutex_active)
	{
		if (type == MTX_LOCK && pthread_mutex_lock(&print_mutex))
			return (3);
		if (type == MTX_UNLOCK && pthread_mutex_unlock(&print_mutex))
			return (4);
	}
	return (0);
}

int	print_error(const char *source, const char *msg)
{
	if (print_mutex(MTX_LOCK) != 0)
		return (-1);
	print_timestamp();
	if (source)
	{
		ft_putstr_fd((char *)source, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putstr_fd((char *)msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	if (print_mutex(MTX_UNLOCK) != 0)
		return (-1);
	return (1);
}

void	exit_error(t_data *data, char *message)
{
	if (message && data->stderr_cpy >= 0)
	{
		if (errno)
			perror(message);
		else
			ft_putendl_fd(message, STDERR_FILENO);
	}
	printf("%s\n", message);
	if (data->stderr_cpy >= 0)
		printf("%s : %s\n", ERR_LOG_INFO, ERR_LOG_FILE);
	printf("%s\n", EXIT_ERR_MSG);
	destroy_data(data);
	exit(EXIT_FAILURE);
}

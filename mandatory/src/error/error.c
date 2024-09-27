/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:49:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/27 18:00:53 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	print_error(const char *source, const char *msg)
{
	const char	unknown_source[] = "unknown source";
	const char	unknown_error[] = "unknown error";

	ft_putendl_fd("Error", STDERR_FILENO);
	if (source)
		ft_putstr_fd((char *)source, STDERR_FILENO);
	else
		ft_putstr_fd((char *)unknown_source, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (msg)
		ft_putstr_fd((char *)msg, STDERR_FILENO);
	else
		ft_putstr_fd((char *)unknown_error, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}

void	exit_error(t_data *data, char *message)
{
	if (errno)
		perror(message);
	else
		ft_putendl_fd(message, STDERR_FILENO);
	ft_putendl_fd("Exiting program...", STDERR_FILENO);
	destroy_data(data);
	exit(EXIT_FAILURE);
}

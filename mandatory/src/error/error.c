/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:49:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/14 14:23:54 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	print_error(const char *source, const char *msg)
{
	if (source)
	{
		ft_putstr_fd((char *)source, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putstr_fd((char *)msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}

void	exit_error(t_data *data, char *message)
{
	if (message)
		ft_putendl_fd(message, STDOUT_FILENO);
	ft_putendl_fd("Exiting program...", STDOUT_FILENO);
	destroy_data(data);
	exit(EXIT_FAILURE);
}

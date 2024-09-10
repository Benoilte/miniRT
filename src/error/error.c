/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:49:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/10 13:16:54 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(const char *source, const char *msg)
{
	const char	unknown_source[] = "unknown source";
	const char	unknown_error[] = "unknown error";

	ft_putendl_fd("Error", STDERR_FILENO);
	if (source)
		write(STDERR_FILENO, source, ft_strlen(source));
	else
		write(STDERR_FILENO, unknown_source, ft_strlen(unknown_source));
	ft_putstr_fd(": ", STDERR_FILENO);
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	else
		write(STDERR_FILENO, unknown_error, ft_strlen(unknown_error));
	write(STDERR_FILENO, "\n", 1);
}

void	exit_error(t_data *data, char *message)
{
	if (errno)
		perror(message);
	else
		ft_putendl_fd(message, STDERR_FILENO);
	destroy_data(data);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:49:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/27 17:27:38 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	separator(void)
{
	write(STDERR_FILENO, ": ", 2);
}

void	print_error(const char *source, const char *msg)
{
	const char	error[] = "ERROR";
	const char	unknown_source[] = "unknown source";
	const char	unknown_error[] = "unknown error";

	write(STDERR_FILENO, error, ft_strlen(error));
	separator();
	if (source)
		write(STDERR_FILENO, source, ft_strlen(source));
	else
		write(STDERR_FILENO, unknown_source, ft_strlen(unknown_source));
	separator();
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

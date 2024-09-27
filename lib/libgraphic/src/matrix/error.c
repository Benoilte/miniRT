/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:28:15 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/19 14:33:22 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static int	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
	{
		if (write(fd, s++, 1) == -1)
			return (-1);
	}
	return (0);
}

static void	separator(void)
{
	ft_putstr_fd(": ", STDERR_FILENO);
}

void	mx_error(const char *source, const char *msg)
{
	const char	warning[] = "WARNING";
	const char	unknown_source[] = "unknown source";
	const char	unknown_error[] = "unknown error";

	ft_putstr_fd(warning, STDERR_FILENO);
	separator();
	if (source)
		ft_putstr_fd(source, STDERR_FILENO);
	else
		ft_putstr_fd(unknown_source, STDERR_FILENO);
	separator();
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	else
		ft_putstr_fd(unknown_error, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

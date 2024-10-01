/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:03:17 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 18:04:12 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	separator(void)
{
	ft_putstr_fd(": ", STDERR_FILENO);
}

void	shape_error(const char *source, const char *msg)
{
	const char	error[] = "ERROR";
	const char	unknown_source[] = "unknown source";
	const char	unknown_error[] = "unknown error";

	ft_putstr_fd((char *)error, STDERR_FILENO);
	separator();
	if (source)
		ft_putstr_fd((char *)source, STDERR_FILENO);
	else
		ft_putstr_fd((char *)unknown_source, STDERR_FILENO);
	separator();
	if (msg)
		ft_putstr_fd((char *)msg, STDERR_FILENO);
	else
		ft_putstr_fd((char *)unknown_error, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

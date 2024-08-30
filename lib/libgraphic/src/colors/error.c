/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:57:04 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/27 16:00:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

static	int	str_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	separator(void)
{
	write(STDERR_FILENO, ": ", 2);
}

void	rgb_error(const char *source, const char *msg)
{
	const char	warning[] = "WARNING";
	const char	unknown_source[] = "unknown source";
	const char	unknown_error[] = "unknown error";

	write(STDERR_FILENO, warning, str_len(warning));
	separator();
	if (source)
		write(STDERR_FILENO, source, str_len(source));
	else
		write(STDERR_FILENO, unknown_source, str_len(unknown_source));
	separator();
	if (msg)
		write(STDERR_FILENO, msg, str_len(msg));
	else
		write(STDERR_FILENO, unknown_error, str_len(unknown_error));
	write(STDERR_FILENO, "\n", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:05:54 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/19 14:20:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the string 's' to the given file descriptor.
*/

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		if (write(fd, s++, 1) == -1)
			return (-1);
	}
	return (0);
}

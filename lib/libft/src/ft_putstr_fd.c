/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:05:54 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:17:12 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the string 's' to the given file descriptor.
*/

#include "../inc/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

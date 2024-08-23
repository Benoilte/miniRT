/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:05:27 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:17:07 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the string 's' to the given file descriptor followed by a newline.
*/

#include "../inc/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

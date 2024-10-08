/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:05:42 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/19 14:22:43 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the integer 'n' to the given file descriptor.
*/

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = (long)n;
	if (nb < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		c = nb + '0';
		if (write(fd, &c, 1) == -1)
			return (-1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:04:39 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:13:48 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc) and returns a string representing the integer 
	received as an argument. Negative numbers must be handled.
*/

#include "../inc/libft.h"

static int	intlen(long n);

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;

	num = (long)n;
	len = intlen(num);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		num *= -1;
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	intlen(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

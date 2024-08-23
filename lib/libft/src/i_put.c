/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_put.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:25:25 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:18:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	i_put_str(char *s)
{
	int	n;

	n = 0;
	if (s == NULL)
		return (i_put_str("(null)"));
	while (s[n])
		write(1, &s[n++], 1);
	return (n);
}

int	i_put_ptr(void *p)
{
	return (i_put_str("0x") + i_put_hex((unsigned long)p, 1));
}

int	i_put_hex(unsigned long n, int case_select)
{
	char	*hex;
	int		count;

	if (case_select)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count += i_put_hex(n / 16, case_select);
		count += i_put_hex(n % 16, case_select);
	}
	else
	{
		write(1, &hex[n], 1);
		return (1);
	}
	return (count);
}

int	i_put_long(long n)
{
	char	c;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += i_put_char('-');
		n *= -1;
	}
	if (n >= 10)
	{
		count += i_put_long(n / 10);
		count += i_put_long(n % 10);
	}
	else
	{
		c = n + '0';
		count += i_put_char(c);
	}
	return (count);
}

int	i_put_int(int n)
{
	long	l;

	l = (long)n;
	if (l < 0)
		return (i_put_char('-') + i_put_long(l * -1));
	else
		return (i_put_long(l));
}

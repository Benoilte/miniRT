/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:32:15 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/19 14:16:12 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	i_put_char(char c)
{
	return (write(1, &c, 1));
}

int	i_put_conversion(va_list args, const char *f_string)
{
	int		n;

	n = 0;
	if (*f_string == 'c')
		n = i_put_char(va_arg(args, int));
	else if (*f_string == 's')
		n = i_put_str(va_arg(args, char *));
	else if (*f_string == 'p')
		n = i_put_ptr(va_arg(args, void *));
	else if (*f_string == 'd' || *f_string == 'i')
		n = i_put_int(va_arg(args, int));
	else if (*f_string == 'u')
		n = i_put_long(va_arg(args, unsigned int));
	else if (*f_string == 'x')
		n = i_put_hex((unsigned int)va_arg(args, int), 1);
	else if (*f_string == 'X')
		n = i_put_hex((unsigned int)va_arg(args, int), 0);
	else if (*f_string == '%')
		n = i_put_char('%');
	return (n);
}

int	ft_printf(const char *f_string, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, f_string);
	while (*f_string)
	{
		if (*f_string == '%')
			count += i_put_conversion(args, ++f_string);
		else
			count += i_put_char(*f_string);
		f_string++;
	}
	va_end(args);
	return (count);
}

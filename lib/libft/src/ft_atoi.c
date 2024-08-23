/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:21:07 by bgolding          #+#    #+#             */
/*   Updated: 2023/10/26 14:42:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *c)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while (ft_isspace(*c))
		c++;
	if (*c == '+')
		c++;
	else if (*c == '-')
	{
		sign = -1;
		c++;
	}
	while (*c && (*c >= '0' && *c <= '9'))
	{
		number *= 10;
		number += *c - '0';
		c++;
	}
	number *= sign;
	return (number);
}

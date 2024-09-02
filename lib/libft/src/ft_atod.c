/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:04:25 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 10:11:10 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_sign(const char **str, int *sign)
{
	if (!str || !sign)
		return ;
	if (*(*str) == '+')
		(*str)++;
	else if (*(*str) == '-')
	{
		*sign = -1;
		(*str)++;
	}
}

static int	increment(double *number, double *scale, int afterdot, char c)
{
	if (!number)
		return (1);
	if (afterdot)
	{
		(*scale) /= 10;
		(*number) += (c - '0') * (*scale);
	}
	else
		(*number) = (*number) * 10.0 + (c - '0');
	return (0);
}

double	ft_atof(const char *str)
{
	double	number;
	int		sign;
	double	scale;
	int		afterdot;

	number = 0;
	sign = 1;
	scale = 1;
	afterdot = 0;
	if (!str)
		return (number);
	while (ft_isspace(*str))
		str++;
	set_sign(&str, &sign);
	while (*str && (ft_isdigit(*str) || (*str == '.' && !afterdot)))
	{
		if (*str == '.')
				afterdot++;
		else
			number = increment(&number, &scale, afterdot, *str);
		str++;
	}
	return (number * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:08:58 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 10:06:05 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_char_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

static void	skip_spaces(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
}

static int	set_sign(char *str)
{
	int	sign;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		if (*str++ == '-')
			sign *= -1;
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nbr;
	int	sign;
	int	base_len;
	int	index;

	i = 0;
	nbr = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	skip_spaces(str);
	sign = set_sign(&str[i]);
	if (base_len == 16 && str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (str[i] && ft_strchr(base, ft_toupper(str[i])))
	{
		index = get_char_index(base, ft_toupper(str[i]));
		if (base[index] == '\0')
			break ;
		nbr *= base_len;
		nbr += index;
		i++;
	}
	return (nbr * sign);
}

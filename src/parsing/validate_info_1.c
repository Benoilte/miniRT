/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:08:18 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 12:33:22 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_brightness(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atod(str), 0, 1))
		return (log_error(errors, ERR_RATIO, line));
	return (0);
}

int	validate_color(const char *str, int line, t_list **errors)
{
	char	**args;
	int		i;

	args = ft_split(str, ',');
	if (!args)
		return (-1);
	i = 0;
	while (i < 3)
	{
		if (!args[i])
			return (free_args(&args), log_error(errors, ERR_ARG_MISSING, line));
		if (!is_real_num(args[i]))
			return (free_args(&args), log_error(errors, ERR_REAL_NUM, line));
		if (!only_digits(args[i])
			|| !(in_range(ft_atoi(args[i]), COLOR_MIN, COLOR_MAX)))
			log_error(errors, ERR_COLOR, line);
		i++;
	}
	if (args[i])
		return (free_args(&args), log_error(errors, ERR_ARG_EXCESS, line));
	free_args(&args);
	return (0);
}

int	validate_coordinate(const char *str, int line, t_list **errors)
{
	char	**args;
	int		i;

	args = ft_split(str, ',');
	if (!args)
		return (-1);
	i = 0;
	while (i < 3)
	{
		if (!args[i])
			return (free_args(&args), log_error(errors, ERR_ARG_MISSING, line));
		if (!is_real_num(args[i]))
			return (free_args(&args), log_error(errors, ERR_REAL_NUM, line));
		if (!in_range(ft_atod(args[1]), RANGE_MIN, RANGE_MAX))
			log_error(errors, ERR_RANGE_LIMIT, line);
		i++;
	}
	if (args[i])
		return (free_args(&args), log_error(errors, ERR_ARG_EXCESS, line));
	free_args(&args);
	return (0);
}

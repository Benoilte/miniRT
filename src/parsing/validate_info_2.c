/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:11:10 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/11 18:53:40 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_vector(const char *str, int line, t_list **errors)
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
			return (free_args(args), log_error(errors, ERR_ARGS_MISSING, line));
		if (!is_real_num(args[i]))
			return (free_args(args), log_error(errors, ERR_REAL_NUM, line));
		if (!in_range(ft_atof(args[i]), VECTOR_RANGE_MIN, VECTOR_RANGE_MAX))
			log_error(errors, ERR_VECTOR_RANGE, line);
		i++;
	}
	if (args[i])
		return (free_args(args), log_error(errors, ERR_ARGS_EXCESS, line));
	free_args(args);
	return (0);
}

int	validate_fov(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atof(str), FOV_MIN, FOV_MAX))
		return (log_error(errors, ERR_FOV, line));
	return (0);
}

int	validate_size(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atof(str), SIZE_MIN, SIZE_MAX))
		return (log_error(errors, ERR_RANGE_LIMIT, line));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus_info_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:38:02 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/23 11:49:57 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_reflective_depth(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!only_digits(str) || \
		!(in_range(ft_atoi(str), REFLECT_RANGE_MIN, REFLECT_RANGE_MAX)))
	{
		return (log_error(errors, ERR_REFLECT_RANGE, line));
	}
	return (0);
}

int	validate_refractive_depth(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!only_digits(str) || \
		!(in_range(ft_atoi(str), REFRACT_RANGE_MIN, REFRACT_RANGE_MAX)))
	{
		return (log_error(errors, ERR_REFRACT_RANGE, line));
	}
	return (0);
}

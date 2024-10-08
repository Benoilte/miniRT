/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus_info_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:32:48 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/08 13:57:07 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_transparency(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atod(str), TRANSPARENCY_MIN, TRANSPARENCY_MAX))
		return (log_error(errors, ERR_RATIO, line));
	return (0);
}

int	validate_refraction_index(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atod(str), REFRACT_INDEX_MIN, REFRACT_INDEX_MAX))
		return (log_error(errors, ERR_B_REFRACT_IDX, line));
	return (0);
}

int	validate_window_width(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!only_digits(str))
		return (log_error(errors, ERR_RES_FORMAT, line));
	if (!in_range(ft_atoi(str), RES_RANGE_W_MIN, RES_RANGE_W_MAX))
		return (log_error(errors, ERR_RES_WIDTH, line));
	return (0);
}

int	validate_window_height(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!only_digits(str))
		return (log_error(errors, ERR_RES_FORMAT, line));
	if (!in_range(ft_atoi(str), RES_RANGE_H_MIN, RES_RANGE_H_MAX))
		return (log_error(errors, ERR_RES_HEIGHT, line));
	return (0);
}

int	validate_depth_value(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!only_digits(str) || \
		!(in_range(ft_atoi(str), DEPTH_RANGE_MIN, DEPTH_RANGE_MAX)))
	{
		return (log_error(errors, ERR_DEPTH, line));
	}
	return (0);
}

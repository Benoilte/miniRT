/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus_info_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:18:56 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 11:56:58 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_diffuse(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atod(str), RATIO_MIN, RATIO_MAX))
		return (log_error(errors, ERR_RATIO, line));
	return (0);
}

int	validate_specular(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atod(str), RATIO_MIN, RATIO_MAX))
		return (log_error(errors, ERR_RATIO, line));
	return (0);
}

int	validate_shininess(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atod(str), SHININESS_MIN, SHININESS_MAX))
		return (log_error(errors, ERR_B_SHINE_RANGE, line));
	return (0);
}

int	validate_reflective(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atod(str), RATIO_MIN, RATIO_MAX))
		return (log_error(errors, ERR_RATIO, line));
	return (0);
}

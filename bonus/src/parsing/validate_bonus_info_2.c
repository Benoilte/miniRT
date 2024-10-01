/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus_info_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:32:48 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 13:34:38 by bgolding         ###   ########.fr       */
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

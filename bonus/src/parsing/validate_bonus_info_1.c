/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus_info_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:18:56 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 10:20:34 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_reflective(const char *str, int line, t_list **errors)
{
	if (!is_real_num(str))
		return (log_error(errors, ERR_REAL_NUM, line));
	if (!in_range(ft_atod(str), 0, 1))
		return (log_error(errors, ERR_RATIO, line));
	return (0);
}

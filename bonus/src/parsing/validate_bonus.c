/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:36:07 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 10:00:39 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_shape_bonus_parameters(char **args, int line, t_list **errors)
{
	if (!args || !errors)
		return (-1);
	if (count_args((const char **)args) != SHAPE_BONUS_PARAMS)
		return (log_error(errors, ERR_BONUS_COUNT, line));
	return (0);
}

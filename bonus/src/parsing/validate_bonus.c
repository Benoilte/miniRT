/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:36:07 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 10:42:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_shape_bonus_parameters(char **args, int line, t_list **errors)
{
	const t_info	info[SHAPE_BONUS_PARAMS] = {INFO_REFLECTIVE};
	int				i;

	if (!args || !errors)
		return (-1);
	i = 0;
	while (i < SHAPE_BONUS_PARAMS)
	{
		if (!args[i])
			return (log_error(errors, ERR_B_ARG_MISSING, line));
		if (validate_info(args[i], line, info[i], errors) == -1)
			return (-1);
		i++;
	}
	if (args[i])
		return (log_error(errors, ERR_ARG_EXCESS, line));
	return (0);
}

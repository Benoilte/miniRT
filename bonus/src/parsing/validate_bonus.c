/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:36:07 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 18:02:04 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_material_parameters(char **args, int line, t_list **errors)
{
	const t_info	info[MATERIAL_PARAMS] = {INFO_DIFFUSE, INFO_SPECULAR, \
		INFO_SHININESS, INFO_REFLECTIVE, INFO_TRANSPARENCY, INFO_REFRACT_INDEX};
	int				i;

	if (!args || !errors)
		return (-1);
	i = 0;
	while (i < MATERIAL_PARAMS)
	{
		if (!args[i])
			return (log_error(errors, ERR_MAT_ARG_MISSING, line));
		if (validate_info(args[i], line, info[i], errors) == -1)
			return (-1);
		i++;
	}
	if (args[i])
		return (log_error(errors, ERR_ARG_EXCESS, line));
	return (0);
}

int	validate_resolution_parameters(char **args, int line, t_list **errors)
{
	const t_info	info[RESOLUTION_PARAMS] = {INFO_WIN_WIDTH, INFO_WIN_HEIGHT};
	int				i;

	if (!args || !errors)
		return (-1);
	i = 0;
	while (i < RESOLUTION_PARAMS)
	{
		if (!args[i])
			return (log_error(errors, ERR_ARG_MISSING, line));
		if (validate_info(args[i], line, info[i], errors) == -1)
			return (-1);
		i++;
	}
	if (args[i])
		return (log_error(errors, ERR_ARG_EXCESS, line));
	return (0);
}

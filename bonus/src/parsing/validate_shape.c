/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:49:36 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 09:58:50 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_sphere(t_token *token, t_list **errors)
{
	const t_info	info[SPHERE_PARAMS] = {INFO_COORD, INFO_SIZE, INFO_COLOR};
	int				i;
	char			**args;

	if (!token || !token->args || !errors)
		return (-1);
	i = 0;
	args = &token->args[1];
	while (i < SPHERE_PARAMS)
	{
		if (!args[i])
			return (log_error(errors, ERR_ARG_MISSING, token->line));
		if (validate_info(args[i], token->line, info[i], errors) == -1)
			return (-1);
		i++;
	}
	if (args[i])
		return (validate_shape_bonus_parameters(&args[i], token->line, errors));
	return (0);
}

int	validate_plane(t_token *token, t_list **errors)
{
	const t_info	info[PLANE_PARAMS] = {INFO_COORD, INFO_VECTOR, INFO_COLOR};
	int				i;
	char			**args;

	if (!token || !token->args || !errors)
		return (-1);
	i = 0;
	args = &token->args[1];
	while (i < PLANE_PARAMS)
	{
		if (!args[i])
			return (log_error(errors, ERR_ARG_MISSING, token->line));
		if (validate_info(args[i], token->line, info[i], errors) == -1)
			return (-1);
		i++;
	}
	if (args[i])
		return (log_error(errors, ERR_ARG_EXCESS, token->line));
	return (0);
}

int	validate_cylinder(t_token *token, t_list **errors)
{
	const t_info	info[CYLINDER_PARAMS] = {\
	INFO_COORD, INFO_VECTOR, INFO_SIZE, INFO_SIZE, INFO_COLOR};
	int				i;
	char			**args;

	if (!token || !token->args || !errors)
		return (-1);
	i = 0;
	args = &token->args[1];
	while (i < CYLINDER_PARAMS)
	{
		if (!args[i])
			return (log_error(errors, ERR_ARG_MISSING, token->line));
		if (validate_info(args[i], token->line, info[i], errors) == -1)
			return (-1);
		i++;
	}
	if (args[i])
		return (log_error(errors, ERR_ARG_EXCESS, token->line));
	return (0);
}

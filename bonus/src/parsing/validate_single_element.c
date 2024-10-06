/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_single_element.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:39:32 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 15:42:50 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_ambient(t_token *token, t_list **errors)
{
	const t_info	info[AMBIENT_PARAMS] = {INFO_BRIGHTNESS, INFO_COLOR};
	int				i;
	char			**args;
	static int		ambient_exists = 0;

	if (!token || !token->args || !errors)
		return (-1);
	if (ambient_exists)
		return (log_error(errors, ERR_DUPLICATE, token->line));
	ambient_exists = 1;
	i = 0;
	args = &token->args[1];
	while (i < AMBIENT_PARAMS)
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

int	validate_camera(t_token *token, t_list **errors)
{
	const t_info	info[CAMERA_PARAMS] = {INFO_COORD, INFO_VECTOR, INFO_FOV};
	int				i;
	char			**args;
	static int		camera_exists = 0;

	if (!token || !token->args || !errors)
		return (-1);
	if (camera_exists)
		return (log_error(errors, ERR_DUPLICATE, token->line));
	camera_exists = 1;
	i = 0;
	args = &token->args[1];
	while (i < CAMERA_PARAMS)
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

int	validate_light(t_token *token, t_list **errors)
{
	const t_info	info[LIGHT_PARAMS] = {\
	INFO_COORD, INFO_BRIGHTNESS, INFO_COLOR};
	int				i;
	char			**args;
	static int		light_exists = 0;

	if (!token || !token->args || !errors)
		return (-1);
	if (light_exists)
		return (log_error(errors, ERR_DUPLICATE, token->line));
	light_exists = 1;
	i = 0;
	args = &token->args[1];
	while (i < LIGHT_PARAMS)
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

int	validate_default_material(t_token *token, t_list **errors)
{
	static int		default_material_exists = 0;

	if (!token || !token->args || !errors)
		return (-1);
	if (default_material_exists)
		return (log_error(errors, ERR_DUPLICATE, token->line));
	default_material_exists = 1;
	return (validate_material_parameters(&token->args[1], token->line, errors));
}

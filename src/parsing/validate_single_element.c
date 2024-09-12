/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_single_element.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:39:32 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 12:33:22 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_ambient(t_token *token, t_list **errors)
{
	const t_info	info[AMBIENT_PARAMS] = {INFO_BRIGHTNESS, INFO_COLOR};
	int				i;
	char			**args;

	if (!token || !token->args || !errors)
		return (-1);
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
	(void)token;
	(void)errors;
	return (0);
}

int	validate_light(t_token *token, t_list **errors)
{
	(void)token;
	(void)errors;
	return (0);
}

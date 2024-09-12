/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_single_element.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:39:32 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 11:31:39 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_ambient(t_token *token, t_list **errors)
{
	const t_info	info[AMBIENT_PARAMS] = {INFO_BRIGHTNESS, INFO_COLOR};
	int		i;

	if (!token || !token->args || !errors)
		return (-1);
	i = 1;
	while (i <= AMBIENT_PARAMS)
	{
		if (!token->args[i])
			return (log_error(errors, ERR_ARGS_MISSING, token->line_number));
		if (validate_info(token->args[i], token->line_number, info[i - 1], errors) == -1)
			return (-1);
		i++;
	}
	if (token->args[i])
		return (log_error(errors, ERR_ARGS_EXCESS, token->line_number));
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

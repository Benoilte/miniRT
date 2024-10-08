/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_single_element_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:42:41 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/08 13:52:08 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	validate_resolution(t_token *token, t_list **errors)
{
	static int	resolution_exists = 0;

	if (!token || !token->args || !errors)
		return (-1);
	if (resolution_exists)
		return (log_error(errors, ERR_DUPLICATE, token->line));
	resolution_exists = 1;
	return (validate_resolution_parameters(&token->args[1], token->line, \
											errors));
}

int	validate_depth(t_token *token, t_list **errors)
{
	static int	depth_exists = 0;

	if (!token || !token->args || !errors)
		return (-1);
	if (depth_exists)
		return (log_error(errors, ERR_DUPLICATE, token->line));
	depth_exists = 1;
	return (validate_depth_parameters(&token->args[1], token->line, errors));
}

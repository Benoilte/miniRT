/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:20:21 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/11 18:58:51 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_id(t_token *token, t_list **errors)
{
	if (token->identifier < 0 || token->identifier >= ID_VALID_COUNT)
		return(log_error(errors, ERR_INVALID_ID, token->line_number));
	return (0);
}

static int	validate_token(t_token *token, t_list **errors)
{
	const t_validate_token	validate[ID_VALID_COUNT] = {\
	validate_ambient, validate_camera, validate_light, \
	validate_sphere, validate_plane, validate_cylinder};

	if (validate_id(token, errors) == -1)
		return (1);
	return (validate[token->identifier](token, errors));
}

static int	validate_syntax(t_input_data *input)
{
	t_list	*node;

	if (!input)
		return (1);
	node = input->token_list;
	while (node)
	{
		if (validate_token((t_token *)node->content, &input->errors) == -1)
			return (-1);
		node = node->next;
	}
	return (0);
}

int	parser(t_input_data *input)
{
	if (validate_syntax(input) == -1)
		return (input_error(input, "parser", SYN_CHK_INCOMPLETE));
	if (input->errors)
		return (input_error(input, "parser", SNY_CHK_ERROR));
	return (0);
}

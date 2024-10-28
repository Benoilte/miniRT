/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:20:21 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/17 07:20:19 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_token(t_token *token, t_list **errors)
{
	const t_validate_token	validate[ID_VALID_COUNT] = {validate_ambient, \
	validate_camera, validate_light, validate_default_material, \
	validate_resolution, validate_depth, validate_a_aliasing, validate_sphere, \
	validate_plane,	validate_cylinder, validate_cube};

	if (token->identifier < 0 || token->identifier >= ID_VALID_COUNT)
		return (log_error(errors, ERR_INVALID_ID, token->line));
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

static int	total_shape_count(int count[ID_VALID_COUNT])
{
	int		shape_count;
	t_id	id;

	shape_count = 0;
	id = ID_SPHERE;
	while (id < ID_VALID_COUNT)
		shape_count += count[id++];
	return (shape_count);
}

static int	validate_world(t_list *tokens)
{
	int		count[ID_VALID_COUNT];
	t_id	id;
	int		errors;

	ft_bzero(&count, sizeof(count));
	while (tokens)
	{
		id = ((t_token *)tokens->content)->identifier;
		count[id]++;
		tokens = tokens->next;
	}
	errors = 0;
	if (count[ID_AMBIENT] < 1)
		errors += input_error(NULL, NULL, WORLD_ERROR_AMB);
	if (count[ID_CAMERA] < 1)
		errors += input_error(NULL, NULL, WORLD_ERROR_CAM);
	if (count[ID_LIGHT] < 1)
		errors += input_error(NULL, NULL, WORLD_ERROR_LIGHT);
	if (total_shape_count(count) < 1)
		errors += input_error(NULL, NULL, WORLD_ERROR_SHAPE);
	if (total_shape_count(count) > WORLD_SHAPE_LIMIT)
		errors += input_error(NULL, NULL, WORLD_ERROR_LIMIT);
	return (errors);
}

int	parser(t_input_data *input)
{
	if (validate_syntax(input) == -1)
		return (input_error(input, "parser", SYN_CHK_INCOMPLETE));
	if (input->errors)
		return (input_error(input, "parser", SYN_CHK_ERROR));
	if (validate_world(input->token_list) != 0)
		return (1);
	return (0);
}

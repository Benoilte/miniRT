/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:03:56 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/10 18:14:25 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validate_number(t_id id, char *arg)
{
	(void)id;
	if (!arg)
		return (false);
	while (*arg)
	{
		if (!ft_isdigit(*arg++))
			return (false);
	}
	return (true);
}

bool	validate_single_char(t_id id, char *arg)
{
	(void)id;
	if (!arg)
		return (false);
	if (ft_strlen(arg) != 1 || !ft_isalpha(*arg))
		return (false);
	return (true);
}

bool	validate_token(t_token *token, t_ast *tree, int level)
{
	if (!token || !tree || !token->args[level])
		return (false);
	if (tree->validate(token->identifier, token->args[level]))
			return (validate_token(token, tree->right, level + 1));
	return (validate_token(token, tree->left, level + 1));
}

t_ast	*new_ast_node(t_validate f)
{
	t_ast	*new;

	new = ft_calloc(1, sizeof(t_ast));
	if (!new)
		return (NULL);
	new->validate = f;
	return (new);
}

t_ast	*build_sytax_tree(void)
{
	t_ast	*tree;

	tree = new_ast_node(validate_number);
	if (!tree)
		return (NULL);
	tree->right = new_ast_node(validate_single_char);
	if (!tree->right)
		return (NULL);
	return (tree);
}

int parse_test(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	
	t_ast	*syntax_tree;	
	syntax_tree = build_sytax_tree();
	if (!syntax_tree)
		return (2);
	
	t_token	*token;
	token = new_token(argv[1], 0);
	if (validate_token(token, syntax_tree, 0) == false)
		ft_printf("false\n");
	else
		ft_printf("true\n");
	free(token);
	free(syntax_tree);
	return (0);
}

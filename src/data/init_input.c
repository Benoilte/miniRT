/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:12:51 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/19 14:44:52 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// FOR TESTING PURPOSES
void	print_args(char **args)
{
	int	i;

	if (!args)
		ft_printf("No args");
	i = 0;
	while (args[i])
		ft_printf("[%s] ", args[i++]);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

// FOR TESTING PURPOSES
void	print_token(void *content)
{
	t_token	*token;

	if (!content)
		return ;
	token = (t_token *)content;
	ft_printf("=== <TOKEN> ===\n");
	ft_printf("identifier:\t%d\n", token->identifier);
	ft_printf("args:\t\t");
	print_args(token->args);
	ft_printf("line:\t\t%d\n", token->line);
	ft_printf("=== <END> ===\n\n");
}

int	init_input(t_input_data *input, int argc, char **argv)
{
	if (!input || !argv)
		return (input_error(input, "init_input", INVALID_POINTER));
	if (argc != 2)
		return (input_error(input, "init_input", INPUT_ERR_USAGE), 2);
	if (validate_file(argv[1], &input->fd) != 0)
		return (3);
	if (lexer(input) != 0)
		return (4);
	if (parser(input) != 0)
		return (5);
	ft_lstiter(input->token_list, print_token);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:31:49 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/08 13:18:44 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_token(void *content);

int	lexer(t_input_data *input)
{
	char	*line;

	if (!input)
		return (input_error(NULL, "init_input", INVALID_POINTER));
	line = get_next_line(input->fd);
	while (line)
	{
		if (ft_strlen(line) && tokenize_line(&input->token_list, line) != 0)
		{
			ft_lstclear(&input->token_list, delete_token);
			free(line);
			return (input_error(input, "lexer", LX_INCOMPLETE));
		}
		free(line);
		line = get_next_line(input->fd);
	}
	ft_lstiter(input->token_list, print_token);
	return (0);
}

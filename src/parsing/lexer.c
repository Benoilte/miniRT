/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:31:49 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 12:05:30 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	lexer(int fd, t_list **token_list)
{
	char	*line;

	if (!token_list)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) && tokenize_line(token_list, line) != 0)
		{
			ft_lstclear(token_list, delete_token);
			free(line);
			print_error("lexer", LX_INCOMPLETE);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

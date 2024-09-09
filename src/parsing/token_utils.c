/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:03:03 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 12:06:26 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	tokenize_error(char *source)
{
	char	buffer[50];

	ft_strcpy(buffer, "tokenize_line: ");
	ft_strlcat(buffer, source, sizeof(buffer));
	print_error(buffer, strerror(errno));
	return (1);
}

static void	free_args(char **args)
{
	if (!args)
		return ;
	while (*args)
	{
		free(*args);
		args++;
	}
	free(args);
}

void	delete_token(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	if (!token)
		return ;
	if (token->args)
		free_args(token->args);
	free(token);
}

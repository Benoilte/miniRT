/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:03:03 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/11 17:49:51 by bgolding         ###   ########.fr       */
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

void	free_args(char **args)
{
	if (!args)
		return ;
	while (*args)
	{
		free(*args);
		args++;
	}
}

void	delete_token(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	if (!token)
		return ;
	if (token->args)
	{
		free_args(token->args);
		free(token->args);
	}
	free(token);
}

static t_id	set_identifier(char *str)
{
	const char	*identifiers[ID_VALID_COUNT] = {\
	STR_AMBIENT, STR_CAMERA, STR_LIGHT, STR_SPHERE, STR_PLANE, STR_CYLINDER};
	int			i;

	if (!str)
		return (ID_INVALID);
	i = 0;
	while (i < ID_VALID_COUNT)
	{
		if (ft_strncmp(str, identifiers[i], ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (ID_INVALID);
}

t_token	*new_token(char *str, int line)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (token)
	{
		token->args = ft_split(str, ' ');
		if (!token->args)
		{
			print_error("new_token: ft_split: ", strerror(errno));
			free(token);
			return (NULL);
		}
		token->identifier = set_identifier(token->args[0]);
		token->line_number = line;
	}
	return (token);
}

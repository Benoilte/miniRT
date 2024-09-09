/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:29:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 12:09:21 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_id	set_identifier(char *str)
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

static t_token	*new_token(char *str, int line)
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

static void	normalize_whitespace(unsigned int i, char *c)
{
	(void)i;
	if (!c)
		return ;
	if (ft_isspace(*c))
		*c = ' ';
}

char	*sanitize_line(char *line)
{
	char	*clean_line;

	if (!line)
		return (NULL);
	clean_line = ft_strtrim(line, " \t\n\v\f\r");
	if (!clean_line)
		return (NULL);
	ft_striteri(clean_line, normalize_whitespace);
	return (clean_line);
}

int	tokenize_line(t_list **token_list, char *line)
{
	static int	line_count = 1;
	t_list		*node;
	t_token		*token;
	char		*clean_line;

	if (!token_list || !line)
		return (-1);
	clean_line = sanitize_line(line);
	if (!clean_line)
		return (tokenize_error("ft_sanitize_line"));
	token = new_token(clean_line, line_count);
	if (!token)
	{
		free(clean_line);
		return (tokenize_error("new_token"));
	}
	node = ft_lstnew(token);
	if (!node)
	{
		delete_token(token);
		return (tokenize_error("ft_lstnew"));
	}
	line_count++;
	ft_lstadd_back(token_list, node);
	return (0);
}

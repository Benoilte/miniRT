/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:29:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 16:03:31 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

static int	only_space(const char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str++))
			return (0);
	}
	return (1);
}

int	tokenize_line(t_list **token_list, char *line)
{
	static int	line_count = 0;
	t_list		*node;
	t_token		*token;
	char		*clean_line;

	if (!token_list || !line)
		return (-1);
	line_count++;
	if (only_space(line))
		return (0);
	clean_line = sanitize_line(line);
	if (!clean_line)
		return (tokenize_error("ft_sanitize_line"));
	token = new_token(clean_line, line_count);
	free(clean_line);
	if (!token)
		return (tokenize_error("new_token"));
	node = ft_lstnew(token);
	if (!node)
	{
		delete_token(token);
		return (tokenize_error("ft_lstnew"));
	}
	ft_lstadd_back(token_list, node);
	return (0);
}

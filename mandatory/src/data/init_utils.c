/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:53:50 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/27 17:04:39 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_ambient(char **str)
{
	return (rgb_scale(str_to_rgb(str[2]), rt_roundf(ft_atod(str[1]))));
}

float	rt_roundf(float val)
{
	return (round(val / EPSILON) * EPSILON);
}

char	**get_element(t_list *token_list, t_id id)
{
	t_token	*token;

	if (!token_list)
		return (print_error("get_element", INVALID_POINTER), NULL);
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->identifier == id)
			return (token->args);
		token_list = token_list->next;
	}
	print_error("get_element", "could not find element in token list");
	return (NULL);
}

t_tuple	str_to_tuple(char *str, int type)
{
	float	x;
	float	y;
	float	z;
	char	*next_value;

	x = rt_roundf(ft_atod(str));
	next_value = ft_strchr(str, ',') + 1;
	y = rt_roundf(ft_atod(next_value));
	next_value = ft_strchr(next_value, ',') + 1;
	z = rt_roundf(ft_atod(next_value));
	if (type == VECTOR)
		return (vector(x, y, z));
	else
		return (point(x, y, z));
}

t_color	str_to_rgb(char *str)
{
	char	*next_value;
	int		color;

	color = (ft_atoi(str) << 16);
	next_value = ft_strchr(str, ',') + 1;
	color |= (ft_atoi(next_value) << 8);
	next_value = ft_strchr(next_value, ',') + 1;
	color |= ft_atoi(next_value);
	return (rgb_itos(color));
}

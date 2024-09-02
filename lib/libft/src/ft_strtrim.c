/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:07:07 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 10:06:05 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc) and returns a copy of 's1' with the characters
	specified in 'set' removed from the beginning and the end of the string.
*/

#include "libft.h"

static int	in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	while (in_set(s1[i], set))
		i++;
	if (i == j || j == 0)
		return (ft_strdup(""));
	while (in_set(s1[j - 1], set))
		j--;
	cpy = ft_calloc(j - i + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s1 + i, j - i);
	cpy[j - i] = '\0';
	return (cpy);
}

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

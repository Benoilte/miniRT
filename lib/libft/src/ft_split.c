/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:06:02 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 10:06:05 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc) and returns an array of strings
	obtained by splitting 's' using the character 'c' as a delimiter.
	The array must end with a NULL pointer.
*/

#include "libft.h"

static int	string_count(char const *s, char c);
static int	next_strlen(const char *s, char c);
static char	**free_array(char **array, int i);
static int	add_string(char *dst, const char *src, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		i;

	count = string_count(s, c);
	array = ft_calloc(count + 1, sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		array[i] = ft_calloc(next_strlen(s, c) + 1, sizeof(char));
		if (!array[i])
			return (free_array(array, i - 1));
		s += add_string(array[i], s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}

static int	string_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	next_strlen(const char *s, char c)
{
	int	n;

	n = 0;
	while (s[n] != c && s[n] != '\0')
		n++;
	return (n);
}

static char	**free_array(char **array, int i)
{
	while (i >= 0)
		free(array[i--]);
	free(array);
	return (NULL);
}

static int	add_string(char *dst, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

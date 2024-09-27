/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:24:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 10:06:05 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc) and returns a substring from the string 's'.
	The substring begins at index 'start' and is of maximum size 'len'.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	if (start > s_len || len == 0 || *s == '\0')
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = ft_calloc(1, len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, &s[start], len);
	return (ptr);
}

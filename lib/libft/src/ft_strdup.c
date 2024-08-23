/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:18:55 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:17:22 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	cpy_size;

	cpy_size = ft_strlen(s1) + 1;
	ptr = (char *)malloc(cpy_size);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, cpy_size);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:06:58 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:17:40 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Applies the function 'f' to each character of the string 's', and passing its
	index as first argument to create a new string (with malloc(3)) resulting
	from successive applications of 'f'.
*/

#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	ptr = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

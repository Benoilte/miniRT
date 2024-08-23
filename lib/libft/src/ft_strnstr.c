/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:16:03 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:17:48 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	n;

	n = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		while (haystack[n] == needle[n])
		{
			if (len - n <= 0)
				return (NULL);
			if (needle[n + 1] == '\0')
				return ((char *)haystack);
			n++;
		}
		n = 0;
		haystack++;
		len--;
	}
	return (NULL);
}

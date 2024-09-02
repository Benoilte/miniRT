/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:40:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 10:06:05 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	if ((!dst && !src) || dst == src)
		return (dst);
	if (tmp_dst > tmp_src)
		while (len-- > 0)
			tmp_dst[len] = tmp_src[len];
	else
		while (len-- > 0)
			*tmp_dst++ = *tmp_src++;
	return (dst);
}

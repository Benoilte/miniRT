/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:28:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/27 15:41:25 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_color	rgb_set(float red, float green, float blue)
{
	return ((t_color){red, green, blue});
}

t_color	*rgb_new(float red, float green, float blue)
{
	t_color	*p;

	p = malloc(sizeof(t_color));
	if (!p)
	{
		perror("rgb_new");
		return (NULL);
	}
	*p = rgb_set(red, green, blue);
	return (p);
}

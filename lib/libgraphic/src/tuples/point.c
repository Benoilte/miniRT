/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:46:11 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 13:05:37 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_point	point(float x, float y, float z)
{
	return ((t_point){x, y, z, POINT});
}

t_point	*alloc_point(float x, float y, float z)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	if (!p)
	{
		perror("alloc_point error");
		return (NULL);
	}
	*p = (t_point){x, y, z, POINT};
	return (p);
}

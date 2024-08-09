/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:02:34 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 13:02:36 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_vector	vector(float x, float y, float z)
{
	return ((t_vector){x, y, z, VECTOR});
}

t_vector	*alloc_vector(float x, float y, float z)
{
	t_vector	*v;

	v = malloc(sizeof(t_vector));
	if (!v)
	{
		perror("alloc_vector error");
		return (NULL);
	}
	*v = (t_vector){x, y, z, VECTOR};
	return (v);
}

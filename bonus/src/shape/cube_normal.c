/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:48:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/21 11:52:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normal_cube(t_shape *shape, t_point *object_point)
{
	float	xabs;
	float	yabs;
	float	zabs;
	float	fmax;

	(void)shape;
	xabs = fabsf(object_point->x);
	yabs = fabsf(object_point->y);
	zabs = fabsf(object_point->z);
	fmax = ft_get_max_f(xabs, yabs, zabs);
	if (equalf(fmax, xabs))
		return (vector(object_point->x, 0, 0));
	if (equalf(fmax, yabs))
		return (vector(0, object_point->y, 0));
	else
		return (vector(0, 0, object_point->z));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:48:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 13:36:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
​ 	​function​ local_normal_at(cube, point)
​ 	  maxc ← max(abs(point.x), abs(point.y), abs(point.z))
​
​ 	  ​if​ maxc = abs(point.x) ​then​
​ 	    ​return​ vector(point.x, 0, 0)
​ 	  ​else​ ​if​ maxc = abs(point.y) ​then​
​ 	    ​return​ vector(0, point.y, 0)
​ 	  ​end​ ​if​
​
​ 	  ​return​ vector(0, 0, point.z)
​ 	​end​ ​function
*/

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

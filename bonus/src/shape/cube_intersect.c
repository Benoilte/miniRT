/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:49:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 12:03:43 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
​ 	​function​ check_axis(origin, direction)
​ 	  tmin_numerator = (-1 - origin)
​ 	  tmax_numerator = (1 - origin)
​
​ 	  ​if​ abs(direction) >= EPSILON
​ 	    tmin ← tmin_numerator / direction
​ 	    tmax ← tmax_numerator / direction
​ 	  ​else​
​ 	    tmin ← tmin_numerator * INFINITY
​ 	    tmax ← tmax_numerator * INFINITY
​ 	  ​end​ ​if​
​
​ 	  ​if​ tmin > tmax ​then​ swap(tmin, tmax)
​
​ 	  ​return​ tmin, tmax
​ 	​end​ ​function
*/

static void	check_axis(t_report *min_max, float origin, float direction)
{
	float	tmin_numerator;
	float	tmax_numerator;

	tmin_numerator = (-1 - origin);
	tmax_numerator = (1 - origin);
	if (greater_or_equalf(fabsf(direction), EPSILON))
	{
		min_max->t[MIN] = tmin_numerator / direction;
		min_max->t[MAX] = tmax_numerator / direction;
	}
	else
	{
		min_max->t[MIN] = ft_get_min_or_max_float(tmin_numerator);
		min_max->t[MAX] = ft_get_min_or_max_float(tmax_numerator);
	}
	if (min_max->t[MIN] > min_max->t[MAX])
		ft_swap(min_max->t, min_max->t + 1);
}

static float	get_largest_min(float x, float y, float z)
{
	if ((x > y) && (x > z))
		return (x);
	if ((y > x) && (y > z))
		return (y);
	else
		return (z);
}

static float	get_smallest_max(float x, float y, float z)
{
	if ((x < y) && (x < z))
		return (x);
	if ((y < x) && (y < z))
		return (y);
	else
		return (z);
}

/*
​ 	​function​ local_intersect(cube, ray)
​ 	  xtmin, xtmax ← check_axis(ray.origin.x, ray.direction.x)
​ 	  ytmin, ytmax ← check_axis(ray.origin.y, ray.direction.y)
​ 	  ztmin, ztmax ← check_axis(ray.origin.z, ray.direction.z)
​ 	  tmin ← max(xtmin, ytmin, ztmin)
​ 	  tmax ← min(xtmax, ytmax, ztmax)
​
​ 	  ​return​ ( intersection(tmin, cube), intersection(tmax, cube) )
​ 	​end​ ​function
*/



bool	intersect_cube(t_ray *ray, t_shape *shape, t_report *report)
{
	t_report	x;
	t_report	y;
	t_report	z;

	if (!ray || !shape || !report)
		return (false);
	check_axis(&x, ray->origin.x, ray->direction.x);
	check_axis(&y, ray->origin.y, ray->direction.y);
	check_axis(&z, ray->origin.z, ray->direction.z);
	report->t[MIN] = get_largest_min(x.t[MIN], y.t[MIN], z.t[MIN]);
	report->t[MAX] = get_smallest_max(x.t[MAX], y.t[MAX], z.t[MAX]);
	if (report->t[MIN] > report->t[MAX])
		return (false);
	report->count = 2;
	return (true);
}

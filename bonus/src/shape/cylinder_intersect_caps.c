/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect_caps.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:32:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/24 14:32:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
​ 	​# a helper function to reduce duplication.​
​ 	​# checks to see if the intersection at `t` is within a radius​
​ 	​# of 1 (the radius of your cylinders) from the y axis.​
​*/

static bool	check_cap(t_ray *ray, float *t, float *radius)
{
	float	x;
	float	z;

	x = ray->origin.x + (*t * ray->direction.x);
	z = ray->origin.z + (*t * ray->direction.z);
	*radius = (fsquaref(x) + fsquaref(z));
	return ((*radius < 1) || equalf(*radius, 1));
}

/*
	If function intersect_cylinder() get only one valid intersection
    after checking the caps intersection of a capped cylinder.
	it means that we face the edge case where the intersection
	happenned exactly in the corner of the cylinder.
	(jonction between cap and cylinder body)
	
    In this case we set the missing intersection
	to the value with the smallest radius computed
*/

static float	get_edge_case(	float *t_min, \
								float *t_max, \
								float *rad_min, \
								float *rad_max)
{
	if (rad_min < rad_max)
		return (*t_min);
	else
		return (*t_max);
}

/*
​ 	  ​# caps only matter if the cylinder is closed, and might possibly be​
​ 	  ​# intersected by the ray.​
​
​ 	  ​# first check for an intersection with the lower end cap by intersecting​
​ 	  ​# the ray with the plane at y=cyl.minimum​
​
​ 	  ​# then check for an intersection with the upper end cap by intersecting​
​ 	  ​# the ray with the plane at y=cyl.maximum​
*/

bool	intersect_caps(t_ray *ray, t_shape *cl, t_report *report)
{
	float	t_min;
	float	t_max;
	float	rad_min;
	float	rad_max;

	if (!cl->cylinder.closed || equalf(ray->direction.y, 0))
		return (report->count > 0);
	t_min = (cl->cylinder.min - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, &t_min, &rad_min))
	{
		report->t[report->count] = t_min;
		report->count++;
	}
	t_max = (cl->cylinder.max - ray->origin.y) / ray->direction.y;
	if ((report->count < 2) && check_cap(ray, &t_max, &rad_max))
	{
		report->t[report->count] = t_max;
		report->count++;
	}
	if (report->count == 1)
	{
		report->t[1] = get_edge_case(&t_min, &t_max, &rad_min, &rad_max);
		report->count = 2;
	}
	return (report->count);
}

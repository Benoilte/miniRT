/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect_caps.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:32:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/27 11:54:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

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

// static void set_unintersect_capped_cylinder(t_report *report,
// float *t_min, float *t_max)
// {
// 	report->t[0] = *t_min;
// 	report->t[1] = *t_max;
// 	report->count = 2;
// }

static float get_edge_case(float *t_min, float *t_max, float *rad_min, float *rad_max)
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
	float	radius_min;
	float	radius_max;

	if (!cl->cylinder.closed || equalf(ray->direction.y, 0))
		return (report->count > 0);
	t_min = (cl->cylinder.min - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, &t_min, &radius_min))
	{
		report->t[report->count] = t_min;
		report->count++;
	}
	t_max = (cl->cylinder.max - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, &t_max, &radius_max))
	{
		report->t[report->count] = t_max;
		report->count++;
	}
	// if (report->count == 0)
	// 	set_unintersect_capped_cylinder(report, &t_min, &t_max);
	if (report->count == 1)
		report->t[report->count++] = get_edge_case(&t_min, &t_max, &radius_min, &radius_max);
	return (true);
}

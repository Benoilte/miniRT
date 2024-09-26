/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/12 16:31:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

static void	ft_swap(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
	Check If the y coordinate is between the minimum and maxmium values.
*/

static void	validate_intersects(t_ray *ray, t_shape *cl, t_report *report)
{
	float	y;
	bool	t_is_set[2];

	ft_memset(t_is_set, 0, sizeof(bool) * 2);
	if (report->t[0] > report->t[1])
		ft_swap(report->t, report->t + 1);
	y = ray->origin.y + (report->t[0] * ray->direction.y);
	if (cl->cylinder.min < y && y < cl->cylinder.max)
	{
		t_is_set[0] = true;
		report->count++;
	}
	y = ray->origin.y + (report->t[1] * ray->direction.y);
	if (cl->cylinder.min < y && y < cl->cylinder.max)
	{
		t_is_set[1] = true;
		report->count++;
	}
	if ((report->count == 1) && t_is_set[1])
		ft_swap(report->t, report->t + 1);
}

/*
​ 	​# a helper function to reduce duplication.​
​ 	​# checks to see if the intersection at `t` is within a radius​
​ 	​# of 1 (the radius of your cylinders) from the y axis.​
​*/

static bool	check_cap(t_ray *ray, float *t)
{
	float	x;
	float	z;
	float	square_x_z;

	x = ray->origin.x + (*t * ray->direction.x);
	z = ray->origin.z + (*t * ray->direction.z);
	square_x_z = (fsquaref(x) + fsquaref(z));
	return ((square_x_z < 1) || equalf(square_x_z, 1));
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

static bool	intersect_caps(t_ray *ray, t_shape *cl, t_report *report)
{
	float	t;

	if (!cl->cylinder.closed || equalf(ray->direction.y, 0))
		return (report->count > 0);
	t = (cl->cylinder.min - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, &t))
	{
		report->t[report->count] = t;
		report->count++;
	}
	t = (cl->cylinder.max - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, &t))
	{
		report->t[report->count] = t;
		report->count++;
	}
	return (report->count == 2);
}

bool	intersect_cylinder(t_ray *ray, t_shape *cl, t_report *report)
{
	float	a;
	float	b;
	float	c;
	float	d;

	if (!ray || !cl || !report)
		return (false);
	report->count = 0;
	a = fsquaref(ray->direction.x) + fsquaref(ray->direction.z);
	if (fabsf(a) < EPSILON)
		return (intersect_caps(ray, cl, report));
	b = (2 * ray->origin.x * ray->direction.x)
		+ (2 * ray->origin.z * ray->direction.z);
	c = fsquaref(ray->origin.x) + fsquaref(ray->origin.z) - 1;
	d = fsquaref(b) - (4 * a * c);
	if (d < 0)
		return (false);
	report->t[0] = (-b - sqrtf(d)) / (2 * a);
	report->t[1] = (-b + sqrtf(d)) / (2 * a);
	validate_intersects(ray, cl, report);
	if (report->count < 2)
		return (intersect_caps(ray, cl, report));
	return (true);
}

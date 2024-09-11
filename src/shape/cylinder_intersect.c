/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 12:40:30 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

/*
​ 	t0 ← (-b - √(disc)) / (2 * a)
​ 	t1 ← (-b + √(disc)) / (2 * a)
​ 	​if​ t0 > t1 ​then​ swap(t0, t1)
»	xs = ()
»
»	y0 ← ray.origin.y + t0 * ray.direction.y
»	​if​ cylinder.minimum < y0 and y0 < cylinder.maximum
»	  add intersection(t0, cylinder) to xs
»	​end​ ​if​
»
»	y1 ← ray.origin.y + t1 * ray.direction.y
»	​if​ cylinder.minimum < y1 and y1 < cylinder.maximum
»	  add intersection(t1, cylinder) to xs
»	​end​ ​if​
»
»	​return​ xs
*/

static void	ft_swap(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	set_intersect_cylinder(t_ray *ray, t_shape *cl, t_report *report)
{
	float	y;

	if (report->t[0] > report->t[1])
	ft_swap(report->t, report->t + 1);
// 	»	y0 ← ray.origin.y + t0 * ray.direction.y
	y = ray->origin.y + (report->t[0] * ray->direction.y);
// »	​if​ cylinder.minimum < y0 and y0 < cylinder.maximum
	if (cl->cylinder.min < y && y < cl->cylinder.max)
		report->count++;
// »	  add intersection(t0, cylinder) to xs
// »	​end​ ​if​
// »
// »	y1 ← ray.origin.y + t1 * ray.direction.y
	y = ray->origin.y + (report->t[1] * ray->direction.y);
// »	​if​ cylinder.minimum < y1 and y1 < cylinder.maximum
	if (cl->cylinder.min < y && y < cl->cylinder.max)
		report->count++;
// »	  add intersection(t1, cylinder) to xs
// »	​end​ ​if​
}

bool	intersect_cylinder(t_ray *ray, t_shape *cl, t_report *report)
{
	float	a;
	float	b;
	float	c;
	float	d;

	if (!ray || !cl || !report)
		return (false);
	a = fsquaref(ray->direction.x) + fsquaref(ray->direction.z);
	if (fabsf(a) < EPSILON)
		return (false);
	b = (2 * ray->origin.x * ray->direction.x)
		+ (2 * ray->origin.z * ray->direction.z);
	c = fsquaref(ray->origin.x) + fsquaref(ray->origin.z) - 1;
	d = fsquaref(b) - (4 * a * c);
	if (d < 0)
		return (false);
	report->t[0] = (-b - sqrtf(d)) / (2 * a);
	report->t[1] = (-b + sqrtf(d)) / (2 * a);
	report->count = 0;
	set_intersect_cylinder(ray, cl, report);
	if (report->count == 0)
		return (false);
	return (true);
}

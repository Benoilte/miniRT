/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 00:17:49 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

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
	report->count = 2;
	return (true);
}

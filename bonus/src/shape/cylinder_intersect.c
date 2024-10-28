/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 11:02:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

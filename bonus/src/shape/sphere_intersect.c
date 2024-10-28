/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:51:20 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 18:08:35 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_sphere(t_ray *ray, t_shape *shape, t_report *report)
{
	t_vector	s_to_r;
	float		a;
	float		b;
	float		c;
	float		d;

	if (!ray || !shape || !report)
		return (false);
	s_to_r = tp_subtract(ray->origin, shape->center);
	a = tp_dot_product(ray->direction, ray->direction);
	b = 2 * tp_dot_product(ray->direction, s_to_r);
	c = tp_dot_product(s_to_r, s_to_r) - shape->sphere.sq_radius;
	d = fsquaref(b) - 4 * a * c;
	if (d < 0)
		return (false);
	d = sqrtf(d);
	report->t[0] = (-b - d) / (2 * a);
	report->t[1] = (-b + d) / (2 * a);
	report->count = 2;
	return (true);
}

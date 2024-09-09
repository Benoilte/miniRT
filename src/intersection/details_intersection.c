/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:30:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/09 18:28:48 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int	is_shadowed(t_world *world, t_point point)
{
	t_intersect_list	*intersects;
	t_intersect_list	*first_hit;
	t_vector			lightv;
	t_ray				r1;
	float				distance;

	lightv = tp_subtract(world->light->position, point);
	distance = tp_magnitude(lightv);
	r1 = ray(point, tp_normalize(lightv));
	intersects = NULL;
	if (intersect_world(&intersects, &r1, world) != 0)
		return (-1);
	first_hit = get_first_hit(&intersects);
	if (first_hit && (((t_intersection *)(first_hit->content))->t < distance
		|| equalf(((t_intersection *)(first_hit->content))->t, distance)))
	{
		dbl_lstclear(&intersects, clear_intersection);
		return (1);
	}
	dbl_lstclear(&intersects, clear_intersection);
	return (0);
}

int	compute_details(t_details *details, \
					t_intersection *hit, \
					t_ray ray, \
					t_world *world)
{
	if (!details || !hit || !world)
	{
		print_error("compute_details", INVALID_POINTER);
		return (1);
	}
	details->shape = hit->shape;
	details->t = hit->t;
	details->position = ray_position(ray, hit->t);
	details->normalv = get_normal(hit->shape, details->position);
	details->eyev = tp_negate(ray.direction);
	if (tp_dot_product(details->normalv, details->eyev) < 0)
	{
		details->inside = 1;
		details->normalv = tp_negate(details->normalv);
	}
	else
		details->inside = 0;
	details->over_point = \
		tp_add(details->position, tp_multiply(details->normalv, EPSILON));
	details->in_shadow = is_shadowed(world, details->over_point);
	if (details->in_shadow == -1)
		return (2);
	return (0);
}

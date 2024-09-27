/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:30:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/26 14:44:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static void	set_first_hit_valid(t_shape *self, t_intersect_list **first_hit)
{
	t_intersection	*hit;

	if (!*first_hit)
		return ;
	hit = ((t_intersection *)((*first_hit)->content));
	if (hit->shape == self)
		*first_hit = (*first_hit)->next;
}

int	is_shadowed(t_shape *self, \
				t_world *world, \
				t_point point, \
				t_details *details)
{
	t_intersect_list	*intersects;
	t_intersect_list	*first_hit;
	t_vector			lightv;
	t_ray				r1;
	float				distance;

	lightv = tp_subtract(world->light->position, point);
	if (tp_dot_product(details->normalv, lightv) < 0)
		return (1);
	distance = tp_magnitude(lightv);
	r1 = ray(point, tp_normalize(lightv));
	intersects = NULL;
	if (intersect_world(&intersects, &r1, world) != 0)
		return (-1);
	first_hit = get_first_hit(&intersects);
	set_first_hit_valid(self, &first_hit);
	if (first_hit && \
		lower_or_equalf(((t_intersection *)(first_hit->content))->t, distance))
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
		return (print_error("compute_details", INVALID_POINTER));
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
	details->over_point = \
		tp_add(details->over_point, tp_multiply(details->eyev, EPSILON));
	details->in_shadow = \
		is_shadowed(details->shape, world, details->over_point, details);
	if (details->in_shadow == -1)
		return (2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:30:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/06 14:07:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

bool	is_shadowed(t_world *world, t_point point)
{
	t_intersect_list	*intersects;
	t_intersect_list	*first_hit;
	t_vector			lightv;
	t_ray				r1;
	float				distance;

	lightv = tp_subtract(world->light->position, point);
	distance = tp_magnitude(lightv);
	r1 = ray(point, tp_normalize(lightv));
	intersects = intersect_world(&r1, world);
	if (!intersects)
		return (false);
	first_hit = get_first_hit(&intersects);
	if (first_hit && ((t_intersection *)(first_hit->content))->t < distance)
	{
		dbl_lstclear(&intersects, clear_intersection);
		return (true);
	}
	dbl_lstclear(&intersects, clear_intersection);
	return (false);
}

t_details	intersect_details(t_intersection *hit, t_ray ray, t_world *world)
{
	t_details	new;

	new.shape = hit->shape;
	new.t = hit->t;
	new.position = ray_position(ray, hit->t);
	new.normalv = get_normal(hit->shape, new.position);
	new.eyev = tp_negate(ray.direction);
	if (tp_dot_product(new.normalv, new.eyev) < 0)
	{
		new.inside = true;
		new.normalv = tp_negate(new.normalv);
	}
	else
		new.inside = false;
	new.over_point = tp_add(new.position, tp_multiply(new.normalv, EPSILON));
	new.in_shadow = is_shadowed(world, new.over_point);
	return (new);
}

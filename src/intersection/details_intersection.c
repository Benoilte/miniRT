/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:30:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/05 16:23:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/*
The algorithm for is_shadowed goes like this:

1. Measure the distance from point to the light source by subtracting point from the light position, and taking the magnitude of the resulting vector. Call this distance.
2. Create a ray from point toward the light source by normalizing the vector from step 1.
3. Intersect the world with that ray.
4. Check to see if there was a hit, and if so, whether t is less than distance. If so, the hit lies between the point and the light source, and the point is in shadow.

​ 	​function​ is_shadowed(world, point)
​ 	  v ← world.light.position - point
​ 	  distance ← magnitude(v)
​ 	  direction ← normalize(v)
​ 	
​ 	  r ← ray(point, direction)
​ 	  intersections ← intersect_world(world, r)
​ 	
​ 	  h ← hit(intersections)
​ 	  ​if​ h is present and h.t < distance
​ 	    ​return​ true
​ 	  ​else​
​ 	    ​return​ false
​ 	  ​end​ ​if​
​ 	​end​ ​function

*/

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

/*
​ 	​# after computing and (if appropriate) negating​
​ 	​# the normal vector...​
​ 	comps.over_point ← comps.point + comps.normalv * EPSILON
*/

t_intersect_details	set_intersect_details(t_intersection *hit, t_ray ray, t_world *world)
{
	t_intersect_details	new;

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

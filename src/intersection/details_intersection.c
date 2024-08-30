/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:30:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/30 15:45:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect_details	set_intersect_details(t_intersection *hit, t_ray ray)
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
	return (new);
}

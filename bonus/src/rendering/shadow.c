/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:50:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 13:20:09 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_first_hit_opaque(t_intersect_list **first_hit)
{
	t_shape	*shape;

	if (!*first_hit)
		return ;
	while (*first_hit)
	{
		shape = ((t_intersection *)(*first_hit)->content)->shape;
		if (shape->material.transparency > 0.5)
			*first_hit = (*first_hit)->next;
		else
			break ;
	}
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
	set_first_hit_opaque(&first_hit);
	if (first_hit && \
		lower_or_equalf(((t_intersection *)(first_hit->content))->t, distance))
	{
		dbl_lstclear(&intersects, clear_intersection);
		return (1);
	}
	dbl_lstclear(&intersects, clear_intersection);
	return (0);
}

int	set_shadow(t_world *world, t_details *details)
{
	details->in_shadow = \
		is_shadowed(details->shape, world, details->over_point, details);
	if (details->in_shadow == -1)
		return (2);
	return (0);
}

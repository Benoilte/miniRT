/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:50:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/24 07:34:05 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_first_hit_opaque(t_intersect_list **first_hit)
{
	if (!*first_hit)
		return ;
	while (*first_hit)
	{
		if ((*first_hit)->intersect.shape->material.transparency > 0.5)
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
	set_first_hit_valid(self, &first_hit, details->inside);
	set_first_hit_opaque(&first_hit);
	if (first_hit && lower_or_equalf(first_hit->intersect.t, distance))
	{
		inter_lstclear(&intersects);
		return (1);
	}
	inter_lstclear(&intersects);
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

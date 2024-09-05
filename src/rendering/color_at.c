/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:38:39 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/05 12:09:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	no_color(void)
{
	const t_color	black = rgb_set(0, 0, 0);

	return (black);
}

t_color	color_at(t_ray *ray, t_world *world)
{
	t_intersect_list	*intersects;
	t_intersect_list	*first_hit;
	t_color				color;
	t_intersect_details	details;

	if (!ray || !world)
	{
		print_error("color_at", INVALID_POINTER);
		return (no_color());
	}
	intersects = intersect_world(ray, world);
	if (!intersects)
		return (no_color());
	first_hit = get_first_hit(&intersects);
	if (!first_hit)
		color = no_color();
	else
	{
		details = set_intersect_details(first_hit->content, *ray, world);
		color = lighting(&details, world->light);
	}
	dbl_lstclear(&intersects, clear_intersection);
	return (color);
}

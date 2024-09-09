/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:38:39 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 18:09:52 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	no_color(void)
{
	const t_color	black = rgb_set(0, 0, 0);

	return (black);
}

int	color_at(t_color *color, t_ray *ray, t_world *world)
{
	t_intersect_list	*intersects;
	t_intersect_list	*first_hit;
	t_details			details;

	if (!ray || !world)
		return (print_error("color_at", INVALID_POINTER));
	ft_bzero(&details, sizeof(details));
	intersects = NULL;
	if (intersect_world(&intersects, ray, world) != 0)
		return (2);
	first_hit = get_first_hit(&intersects);
	if (!first_hit)
		*color = no_color();
	else
	{
		if (compute_details(&details, first_hit->content, *ray, world) != 0)
		{
			dbl_lstclear(&intersects, clear_intersection);
			return (3);
		}
		*color = lighting(&details, world->light);
	}
	dbl_lstclear(&intersects, clear_intersection);
	return (0);
}

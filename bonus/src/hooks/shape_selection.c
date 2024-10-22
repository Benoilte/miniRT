/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:20:29 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 09:46:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_shape	**get_selected_shape_ptr(void)
{
	static t_shape	*selected_shape = NULL;

	return (&selected_shape);
}

t_shape	*get_selected_shape(void)
{
	return (*get_selected_shape_ptr());
}

void	set_selected_shape(t_shape *new)
{
	*(get_selected_shape_ptr()) = new;
}

t_shape	*select_shape(int x, int y, t_data *data)
{
	t_pixel				pixel;
	t_ray				ray;
	t_intersect_list	*intersects;
	t_intersect_list	*hit;
	t_shape				*selected;

	pixel = (t_pixel){x, y, 0, 0};
	ray = ray_for_pixel(*(data->camera), &pixel);
	intersects = NULL;
	selected = NULL;
	if (intersect_world(&intersects, &ray, data->world) != 0)
		ft_printf("Click : unable to compute intersections (error)\n");
	else
	{
		hit = get_first_hit(&intersects);
		if (hit)
		{
			selected = hit->intersect.shape;
			set_selected_shape(selected);
		}
	}
	inter_lstclear(&intersects);
	return (selected);
}

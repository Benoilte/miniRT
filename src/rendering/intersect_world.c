/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:28:49 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/04 15:44:57 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	reset_report(t_intersect_report *report)
{
	const size_t	size = sizeof(t_intersect_report);

	ft_bzero(report, size);
}

static int	add_intersects_to_list(	t_intersect_list **list, \
									t_intersect_report *report, \
									t_shape *shape)
{
	t_intersection		*new_intersect;
	t_intersect_list	*new_node;

	if (!list || !report || !shape)
		return (print_error("add_intersects_to_list", INVALID_POINTER), 1);
	while (report->count--)
	{
		new_intersect = new_intersection(shape, report->t[report->count]);
		if (!new_intersect)
		{
			print_error("add_intersects_to_list", strerror(errno));
			return (2);
		}
		new_node = dbl_lstnew(new_intersect);
		if (!new_node)
		{
			free(new_intersect);
			print_error("add_intersects_to_list", strerror(errno));
			return (3);
		}
		dbl_lstadd_ordered(list, new_node, add_new_before_lst);
	}
	return (0);
}

static int	intersect_all_shapes(	t_ray *r, \
									t_shape_list *node, \
									t_intersect_list **list)
{
	t_shape				*shape;
	t_intersect_report	report;
	t_ray				transformed_ray;

	if (!r || ! node || !list)
		return (print_error("intersect_all_shapes", INVALID_POINTER), 1);
	while (node)
	{
		shape = (t_shape *)node->content;
		transformed_ray = transform_ray(r, shape->inverse);
		if (shape->f->intersect(&transformed_ray, shape, &report) == true)
		{
			if (add_intersects_to_list(list, &report, shape) != 0)
				return (2);
			reset_report(&report);
		}
		node = node->next;
	}
	return (0);
}

/*
	To debate:
	-	Return a linked list:
		-	Clearer code
		-	Can't distinguish between errors / no intersections found
		-	Any error would report for every pixel iterated over in
			calling function
	-	Return a status code (int)
		-	More complex code (extra list pointer passed as argument)
		-	Can distinguish between errors / no intersections
*/
t_intersect_list	*intersect_world(t_ray *ray, t_world *world)
{
	t_intersect_list	*list;
	t_shape_list		*shape_node;
	t_shape				*shape;

	list = NULL;
	if (!ray || !world)
		print_error("intersect_world", INVALID_POINTER);
	else if (intersect_all_shapes(ray, world->shapes, &list) != 0)
		print_error("intersect_world", INTERSECT_INCOMPLETE);
	return (list);
}

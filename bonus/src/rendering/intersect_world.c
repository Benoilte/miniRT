/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:28:49 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 18:34:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	reset_report(t_report *report)
{
	const size_t	size = sizeof(t_report);

	ft_bzero(report, size);
}

static int	add_intersects_to_list(	t_intersect_list **list, \
									t_report *report, \
									t_shape *shape)
{
	t_intersect_list	*new_intersect;

	if (!list || !report || !shape)
		return (print_error("add_intersects_to_list", INVALID_POINTER), 1);
	while (report->count--)
	{
		new_intersect = inter_lstnew(shape, report->t[report->count]);
		if (!new_intersect)
		{
			print_error("add_intersects_to_list", strerror(errno));
			return (2);
		}
		inter_lstadd_ordered(list, new_intersect, add_new_before_lst);
	}
	return (0);
}

static int	intersect_all_shapes(	t_ray *ray, \
									t_shape_list *node, \
									t_intersect_list **list)
{
	t_shape		*shape;
	t_report	report;
	t_ray		transformed_ray;

	if (!ray || ! node || !list)
		return (print_error("intersect_all_shapes", INVALID_POINTER), 1);
	while (node)
	{
		shape = (t_shape *)node->content;
		transformed_ray = transform_ray(ray, shape->inverse);
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

int	intersect_world(t_intersect_list **list, t_ray *ray, t_world *world)
{
	if (!list || !ray || !world)
	{
		print_error("intersect_world", INVALID_POINTER);
		return (1);
	}
	else if (intersect_all_shapes(ray, world->shapes, list) != 0)
	{
		print_error("intersect_world", INTERSECT_INCOMPLETE);
		return (2);
	}
	return (0);
}

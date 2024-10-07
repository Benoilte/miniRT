/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:30:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 14:47:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_over_point(t_details *details)
{
	details->over_point = \
		tp_add(details->position, tp_multiply(details->normalv, EPSILON));
	details->over_point = \
		tp_add(details->over_point, tp_multiply(details->eyev, EPSILON));
}

void	set_under_point(t_details *details)
{
	const float	default_inside_offset[SHAPE_COUNT] = {\
													SP_INSIDE_DEFAULT_OFSSET, \
													PL_INSIDE_DEFAULT_OFSSET, \
													CL_INSIDE_DEFAULT_OFSSET};
	float		offset;

	offset = default_inside_offset[details->shape->type];
	details->under_point = \
		tp_subtract(details->position, tp_multiply(details->normalv, offset));
	details->under_point = \
		tp_subtract(details->under_point, tp_multiply(details->eyev, offset));
}

int	compute_details(t_details *details, \
					t_intersection *hit, \
					t_ray ray)
{
	if (!details || !hit)
		return (print_error("compute_details", INVALID_POINTER));
	details->shape = hit->shape;
	details->t = hit->t;
	details->position = ray_position(ray, hit->t);
	details->normalv = get_normal(hit->shape, details->position);
	details->eyev = tp_negate(ray.direction);
	if (tp_dot_product(details->normalv, details->eyev) < 0)
	{
		details->inside = 1;
		details->normalv = tp_negate(details->normalv);
	}
	else
		details->inside = 0;
	details->reflectv = tp_reflect(ray.direction, details->normalv);
	set_over_point(details);
	return (0);
}

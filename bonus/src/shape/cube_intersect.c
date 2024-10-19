/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:49:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/19 21:56:39 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_axis(t_report *min_max, float origin, float direction)
{
	float	tmin_numerator;
	float	tmax_numerator;

	tmin_numerator = (-1 - origin);
	tmax_numerator = (1 - origin);
	if (equalf(direction, 0))
	{
		min_max->t[MIN] = ft_get_min_or_max_f(tmin_numerator);
		min_max->t[MAX] = ft_get_min_or_max_f(tmax_numerator);
	}
	else if (greater_or_equalf(direction, EPSILON))
	{
		min_max->t[MIN] = tmin_numerator / direction;
		min_max->t[MAX] = tmax_numerator / direction;
	}
	else
	{
		min_max->t[MIN] = tmax_numerator / direction;
		min_max->t[MAX] = tmin_numerator / direction;
	}
}

bool	intersect_cube(t_ray *ray, t_shape *shape, t_report *report)
{
	t_report	x;
	t_report	y;
	t_report	z;

	if (!ray || !shape || !report)
		return (false);
	check_axis(&x, ray->origin.x, ray->direction.x);
	check_axis(&y, ray->origin.y, ray->direction.y);
	check_axis(&z, ray->origin.z, ray->direction.z);
	report->t[MIN] = ft_get_max_f(x.t[MIN], y.t[MIN], z.t[MIN]);
	report->t[MAX] = ft_get_min_f(x.t[MAX], y.t[MAX], z.t[MAX]);
	if (report->t[MIN] > report->t[MAX])
		return (false);
	report->count = 2;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:49:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 09:01:29 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_cube(t_ray *ray, t_shape *shape, t_report *report)
{
	if (!ray || !shape || !report)
		return (false);
	report->t[0] = 1;
	report->t[1] = 2;
	report->count = 2;
	return (true);
}

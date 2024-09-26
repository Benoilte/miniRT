/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:41:01 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/24 18:24:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_m4x4	mx_orientation(t_vector forward, t_vector up)
{
	t_vector	left;
	t_vector	true_up;

	if (tp_equal(forward, vector(0, -1, 0)))
		left = vector(-1, 0, 0);
	else
		left = tp_normalize(tp_cross_product(forward, tp_normalize(up)));
	true_up = tp_cross_product(left, forward);
	return ((t_m4x4){{\
		{left.x, left.y, left.z, 0}, \
		{true_up.x, true_up.y, true_up.z, 0}, \
		{-forward.x, -forward.y, -forward.z, 0}, \
		{0, 0, 0, 1}}});
}

t_m4x4	view_transform(t_point from, t_vector forward, t_vector up)
{
	t_m4x4	orientation;

	orientation = mx_orientation(forward, up);
	return (mx_mult(orientation, mx_translation(-from.x, -from.y, -from.z)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:41:01 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 15:56:56 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	get_left(t_vector forward, t_vector up)
{
	return (tp_normalize(tp_cross_product(forward, up)));
}

t_vector	get_true_up(t_vector forward)
{
	const t_vector	default_up = vector(0, 1, 0);
	t_vector		left;

	if (tp_equal(forward, vector(0, -1, 0)))
		left = vector(-1, 0, 0);
	else
		left = get_left(forward, default_up);
	return (tp_normalize(tp_cross_product(left, forward)));
}

static t_m4x4	mx_orientation(t_vector forward, t_vector up)
{
	t_vector	left;

	left = get_left(forward, up);
	return ((t_m4x4){{\
		{left.x, left.y, left.z, 0}, \
		{up.x, up.y, up.z, 0}, \
		{-forward.x, -forward.y, -forward.z, 0}, \
		{0, 0, 0, 1}}});
}

t_m4x4	view_transform(t_camera *c)
{
	return (mx_mult(\
		mx_orientation(c->forward, c->up), \
		mx_translation(-(c->from.x), -(c->from.y), -(c->from.z))));
}

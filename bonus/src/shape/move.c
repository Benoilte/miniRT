/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:42:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 15:56:21 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_shape_origin(t_shape *self, t_vector move)
{
	self->transform = mx_add_translation(self->transform, \
		move.x, move.y, move.z);
	self->inverse = mx_inversion(self->transform);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rodrigues_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:44:54 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 10:09:41 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
	Returns the rotation matrix to apply a rotation of 'angle' radians
	around the 'axis' following the right hand rule.
	Rodrigues' formula: R = I + (sinθ)K + (1 - cosθ)K²
*/
t_m4x4	mx_rodrigues_rotate(t_vector axis, float angle)
{
	const float		cos_angle = cos(angle);
	const float		sin_angle = sin(angle);
	t_m4x4			k;
	t_m4x4			rotation;

	k = mx_skew_symmetric(tp_normalize(axis));
	rotation = mx_add(mx_identity(), mx_mult_scalar(k, sin_angle));
	rotation = mx_add(rotation, mx_mult_scalar(mx_mult(k, k), 1 - cos_angle));
	return (rotation);
}

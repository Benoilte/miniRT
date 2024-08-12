/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:58:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 13:26:15 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_m4x4	mx_rotation_x(float r)
{
	return ((t_m4x4){{\
		{1, 0, 0, 0}, \
		{0, cos(r), -sin(r), 0}, \
		{0, sin(r), cos(r), 0}, \
		{0, 0, 0, 1}}});
}

static t_m4x4	mx_rotation_y(float r)
{
	return ((t_m4x4){{\
		{cos(r), 0, sin(r), 0}, \
		{0, 1, 0, 0}, \
		{-sin(r), 0, cos(r), 0}, \
		{0, 0, 0, 1}}});
}

static t_m4x4	mx_rotation_z(float r)
{
	return ((t_m4x4){{\
		{cos(r), -sin(r), 0, 0}, \
		{sin(r), cos(r), 0, 0}, \
		{0, 0, 1, 0}, \
		{0, 0, 0, 1}}});
}

t_m4x4	mx_rotation(float radians, int axis)
{
	if (axis == X_AXIS)
		return (mx_rotation_x(radians));
	if (axis == Y_AXIS)
		return (mx_rotation_y(radians));
	if (axis == Z_AXIS)
		return (mx_rotation_z(radians));
	mx_error("mx_rotation", MX_AXIS_ERROR);
	return (mx_identity());
}

t_m4x4	mx_add_rotation(t_m4x4 m, float radians, int axis)
{
	return (mx_mult(mx_rotation(radians, axis), m));
}

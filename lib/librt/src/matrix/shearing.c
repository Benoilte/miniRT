/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:43:09 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 13:49:07 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4x4	mx_shearing(t_shear_params shear)
{
	return ((t_m4x4){{\
	{1, shear.xy, shear.xz, 0}, \
	{shear.yx, 1, shear.yz, 0}, \
	{shear.zx, shear.zy, 1, 0}, \
	{0, 0, 0, 1}}});
}

t_m4x4	mx_add_shearing(t_m4x4 m, t_shear_params shear)
{
	return (mx_mult(mx_shearing(shear), m));
}

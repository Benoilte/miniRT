/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:01:04 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 13:11:09 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4x4	mx_scaling(float x, float y, float z)
{
	return ((t_m4x4){{\
		{x, 0, 0, 0}, \
		{0, y, 0, 0}, \
		{0, 0, z, 0}, \
		{0, 0, 0, 1}}});
}

t_m4x4	mx_add_scaling(t_m4x4 m, float x, float y, float z)
{
	return (mx_mult(mx_scaling(x, y, z), m));
}

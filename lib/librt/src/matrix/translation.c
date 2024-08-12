/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:36:10 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 13:12:17 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4x4	mx_translation(float x, float y, float z)
{
	return ((t_m4x4){{\
		{1, 0, 0, x}, \
		{0, 1, 0, y}, \
		{0, 0, 1, z}, \
		{0, 0, 0, 1}}});
}

t_m4x4	mx_add_translation(t_m4x4 m, float x, float y, float z)
{
	return (mx_mult(mx_translation(x, y, z), m));
}

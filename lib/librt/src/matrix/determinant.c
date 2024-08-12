/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:31:32 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 11:37:45 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	mx_determinant_2x2(t_m2x2 m)
{
	return ((m.data[0][0] * m.data[1][1]) - (m.data[0][1] * m.data[1][0]));
} 	 

float	mx_determinant_3x3(t_m3x3 m)
{
	return ((m.data[0][0] * mx_cofactor_3x3(m, 0, 0))
		+ (m.data[0][1] * mx_cofactor_3x3(m, 0, 1))
		+ (m.data[0][2] * mx_cofactor_3x3(m, 0, 2)));
}

float	mx_determinant(t_m4x4 m)
{
	return ((m.data[0][0] * mx_cofactor(m, 0, 0))
		+ (m.data[0][1] * mx_cofactor(m, 0, 1))
		+ (m.data[0][2] * mx_cofactor(m, 0, 2))
		+ (m.data[0][3] * mx_cofactor(m, 0, 3)));
}

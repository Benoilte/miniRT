/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:42:14 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 11:46:12 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4x4	mx_inversion(t_m4x4 m)
{
	t_m4x4		inverted;
	int			row;
	int			col;
	float		det;

	det = mx_determinant(m);
	if (equalf(det, 0))
	{
		mx_error("mx_inversion", MX_INV_ERROR);
		return (m);
	}
	row = 0;
	while (row < MAT4X4_SIZE)
	{
		col = 0;
		while (col < MAT4X4_SIZE)
		{
			inverted.data[col][row] = mx_cofactor(m, row, col) / det;
			col++;
 		}
		row++;
	}
	return (inverted);
}

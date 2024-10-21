/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:55:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/21 08:52:02 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static float	dot_product_row_a_col_b(t_m4x4 a, t_m4x4 b, int row, int col)
{
	int		i;
	float	product;

	product = 0;
	i = 0;
	while (i < MAT4X4_SIZE)
	{
		product += a.data[row][i] * b.data[i][col];
		i++;
	}
	return (product);
}

t_m4x4	mx_mult(t_m4x4 a, t_m4x4 b)
{
	t_m4x4	new;
	int		row;
	int		col;

	row = 0;
	while (row < MAT4X4_SIZE)
	{
		col = 0;
		while (col < MAT4X4_SIZE)
		{
			new.data[row][col] = dot_product_row_a_col_b(a, b, row, col);
			col++;
		}
		row++;
	}
	return (new);
}

t_tuple	mx_mult_tuple(t_m4x4 a, t_tuple tuple)
{
	t_tuple	t;

	t.x = (a.data[0][0] * tuple.x) + (a.data[0][1] * tuple.y) \
		+ (a.data[0][2] * tuple.z) + (a.data[0][3] * tuple.w);
	t.y = (a.data[1][0] * tuple.x) + (a.data[1][1] * tuple.y) \
		+ (a.data[1][2] * tuple.z) + (a.data[1][3] * tuple.w);
	t.z = (a.data[2][0] * tuple.x) + (a.data[2][1] * tuple.y) \
		+ (a.data[2][2] * tuple.z) + (a.data[2][3] * tuple.w);
	t.w = (a.data[3][0] * tuple.x) + (a.data[3][1] * tuple.y) \
		+ (a.data[3][2] * tuple.z) + (a.data[3][3] * tuple.w);
	return (t);
}

t_m4x4	mx_mult_scalar(t_m4x4 m, float s)
{
	return ((t_m4x4){{\
	{m.data[0][0] * s, m.data[0][1] * s, m.data[0][2] * s, m.data[0][3] * s}, \
	{m.data[1][0] * s, m.data[1][1] * s, m.data[1][2] * s, m.data[1][3] * s}, \
	{m.data[2][0] * s, m.data[2][1] * s, m.data[2][2] * s, m.data[2][3] * s}, \
	{m.data[3][0] * s, m.data[3][1] * s, m.data[3][2] * s, m.data[3][3] * s}}});
}

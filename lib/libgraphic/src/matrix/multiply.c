/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:55:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/06 17:42:32 by bgolding         ###   ########.fr       */
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

static float    dot_product_row_tuple(float *row, t_tuple *t)
{
    return ((row[0] * t->x) + (row[1] * t->y) + (row[2] * t->z) + (row[3] * t->w));
}

t_tuple	mx_mult_tuple(t_m4x4 a, t_tuple tuple)
{
	t_tuple t;

    t.x = dot_product_row_tuple(a.data[0], &tuple);
    t.y = dot_product_row_tuple(a.data[1], &tuple);
    t.z = dot_product_row_tuple(a.data[2], &tuple);
    t.w = dot_product_row_tuple(a.data[3], &tuple);
	return (t);
}

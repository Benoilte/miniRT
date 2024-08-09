/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:55:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/09 14:25:23 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static float	get_product(t_m4x4 a, t_m4x4 b, int row, int col)
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
			new.data[row][col] = get_product(a, b, row, col);
			col++;
		}
		row++;
	}
	return (new);
}

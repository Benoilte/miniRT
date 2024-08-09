/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:55:43 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/09 14:25:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

bool	mx_equal(t_m4x4 a, t_m4x4 b)
{
	int	row;
	int	col;

	row = 0;
	while (row < MAT4X4_SIZE)
	{
		col = 0;
		while (col < MAT4X4_SIZE)
		{
			if (!equalf(a.data[row][col], b.data[row][col]))
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}

bool	mx_equal_3x3(t_m3x3 a, t_m3x3 b)
{
	int	row;
	int	col;

	row = 0;
	while (row < MAT3X3_SIZE)
	{
		col = 0;
		while (col < MAT3X3_SIZE)
		{
			if (!equalf(a.data[row][col], b.data[row][col]))
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}

bool	mx_equal_2x2(t_m2x2 a, t_m2x2 b)
{
	int	row;
	int	col;

	row = 0;
	while (row < MAT2X2_SIZE)
	{
		col = 0;
		while (col < MAT2X2_SIZE)
		{
			if (!equalf(a.data[row][col], b.data[row][col]))
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}

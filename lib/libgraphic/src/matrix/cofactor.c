/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:31:44 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 11:40:44 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	mx_cofactor_3x3(t_m3x3 a, int sub_row, int sub_col)
{
	float		minor;

	minor = mx_determinant_2x2(mx_submatrix_3x3(a, sub_row, sub_col));
	if ((sub_row + sub_col) & 1)
		return (minor * -1);
	return (minor);
}

float	mx_cofactor(t_m4x4 a, int sub_row, int sub_col)
{
	float	minor;

	minor = mx_determinant_3x3(mx_submatrix(a, sub_row, sub_col));
	if ((sub_row + sub_col) & 1)
		return (minor * -1);
	return (minor);
}

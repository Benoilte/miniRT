/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:32:20 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 08:35:01 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
	Adds two 4x4 matrices together element-wise
*/
t_m4x4	mx_add(t_m4x4 a, t_m4x4 b)
{
	return ((t_m4x4){{\
		{a.data[0][0] + b.data[0][0], a.data[0][1] + b.data[0][1], \
			a.data[0][2] + b.data[0][2], a.data[0][3] + b.data[0][3]}, \
		{a.data[1][0] + b.data[1][0], a.data[1][1] + b.data[1][1], \
			a.data[1][2] + b.data[1][2], a.data[1][3] + b.data[1][3]}, \
		{a.data[2][0] + b.data[2][0], a.data[2][1] + b.data[2][1], \
			a.data[2][2] + b.data[2][2], a.data[2][3] + b.data[2][3]}, \
		{a.data[3][0] + b.data[3][0], a.data[3][1] + b.data[3][1], \
			a.data[3][2] + b.data[3][2], a.data[3][3] + b.data[3][3]}}});
}

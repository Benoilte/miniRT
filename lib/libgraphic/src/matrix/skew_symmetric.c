/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skew_symmetric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:15:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 08:35:18 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
	Creates a skew-symmetric matrix from a vector
*/
t_m4x4	mx_skew_symmetric(t_vector v)
{
	return ((t_m4x4){{\
		{0, -v.z, v.y, 0}, \
		{v.z, 0, -v.x, 0}, \
		{-v.y, v.x, 0, 0}, \
		{0, 0, 0, 0}}});
}

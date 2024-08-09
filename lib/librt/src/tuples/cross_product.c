/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:30:17 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 11:11:36 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_vector	tp_cross_product(t_vector a, t_vector b)
{
	if (!equalf(a.w, VECTOR) || !equalf(b.w, VECTOR))
		tp_error("tp_cross_product", TP_CROSS_ERROR);
	return ((t_vector){\
		a.y * b.z - a.z * b.y, \
		a.z * b.x - a.x * b.z, \
		a.x * b.y - a.y * b.x, \
		VECTOR});
}

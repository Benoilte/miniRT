/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:42:51 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 11:14:44 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float	tp_dot_product(t_vector a, t_vector b)
{
	if (!equalf(a.w, VECTOR) || !equalf(b.w, VECTOR))
		tp_error("tp_dot_product", TP_DOT_ERROR);
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

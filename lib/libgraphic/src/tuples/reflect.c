/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 00:17:38 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/28 00:25:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

/*
normal argument is a vector that points perpendicular
to a surface at a given point.
*/

t_vector	tp_reflect(t_vector in, t_vector normal)
{
	float		dot;

	dot = tp_dot_product(in, normal);
	return (tp_subtract(in, tp_multiply(normal, 2 * dot)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:19:08 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 11:00:41 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

static float	fsquaref(float f)
{
	return (f * f);
}

float	tp_magnitude(t_vector vec)
{
	if (!equalf(vec.w, VECTOR))
		tp_error("tp_magnitude", TP_MAG_ERROR);
	return (sqrtf(fsquaref(vec.x) + fsquaref(vec.y) + fsquaref(vec.z)));
}

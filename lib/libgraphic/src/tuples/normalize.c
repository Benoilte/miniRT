/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:53:10 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 11:05:44 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_vector	tp_normalize(t_vector t)
{
	float	mag;

	if (!equalf(t.w, VECTOR))
		tp_error("tp_normalize", TP_NORM_ERROR1);
	mag = tp_magnitude(t);
	if (equalf(mag, 0))
	{
		tp_error("tp_normalize", TP_NORM_ERROR2);
		return (t);
	}
	return ((t_vector){t.x / mag, t.y / mag, t.z / mag, VECTOR});
}

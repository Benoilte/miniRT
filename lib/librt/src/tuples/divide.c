/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:04:13 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 10:55:19 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tp_divide(t_tuple t, float d)
{
	if (equalf(d, 0))
	{
		tp_error("tp_divide", TP_DIV_ERROR);
		return (t);
	}
	return ((t_tuple){t.x / d, t.y / d, t.z / d, t.w});
}

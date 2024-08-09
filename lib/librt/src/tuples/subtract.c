/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:49:41 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 10:31:30 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tp_subtract(t_tuple a, t_tuple b)
{
	if (a.w - b.w < 0)
		tp_error("tp_subtract", TP_SUB_ERROR);
	return ((t_tuple){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w});
}

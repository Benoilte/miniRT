/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:32:40 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 13:58:08 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	tp_equal(t_tuple a, t_tuple b)
{
	return (equalf(a.x, b.x)
		&& equalf(a.y, b.y)
		&& equalf(a.z, b.z)
		&& equalf(a.w, b.w));
}

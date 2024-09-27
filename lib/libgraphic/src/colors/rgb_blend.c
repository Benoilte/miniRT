/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_blend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:48:53 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 16:04:23 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/*	Returns a blend of the colors a and b based on the prodided weight factor.
	Weight should be in range[0-1] where
	0 means 100% of a and 1 means 100% of b.*/
t_color	rgb_blend(t_color a, t_color b, float weight)
{
	if (weight < 0)
		weight = 0;
	if (weight > 1)
		weight = 1;
	return ((t_color){\
		(1 - weight) * a.red + weight * b.red,
		(1 - weight) * a.green + weight * b.green,
		(1 - weight) * a.blue + weight * b.blue});
}

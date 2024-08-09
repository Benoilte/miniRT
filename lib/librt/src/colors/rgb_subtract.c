/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_subtract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:46:04 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 15:17:46 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/*	Returns the result of subtracting c2 values from c1 values.*/
t_color	rgb_sub(t_color c1, t_color c2)
{
	return ((t_color){c1.red - c2.red, c1.green - c2.green, c1.blue - c2.blue});
}

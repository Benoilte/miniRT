/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:43:40 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 15:17:34 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/*	Returns the result of adding colors c1 and c2 (not a blend).*/
t_color	rgb_add(t_color c1, t_color c2)
{
	return ((t_color){c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue});
}

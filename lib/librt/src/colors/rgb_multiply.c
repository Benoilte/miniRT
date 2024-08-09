/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:51:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 15:54:33 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/*	Returns the Schur product (Hadamard product) of colors a and b,
	effectively multiplying each element by its corresponding one.*/
t_color	rgb_mult(t_color a, t_color b)
{
	return ((t_color){a.red * b.red, a.green * b.green, a.blue * b.blue});
}

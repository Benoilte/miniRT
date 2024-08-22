/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:40:59 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 16:59:29 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

static int	stoi(float scalar)
{
	if (scalar >= 1.0f)
		return (255);
	if (scalar <= 0.0f)
		return (0);
	return (lrintf(scalar * 255.0));
}

/*	Converts a t_color into a singular integer representation.
	Warning: Accuracy is limited to 1/256th for each element.
	Rounding applied through lrintf().*/
int	rgb_stoi(t_color c)
{
	return (stoi(c.red) << 16 | stoi(c.green) << 8 | stoi(c.blue));
}

static float	itos(int i)
{
	return (i / 255.0f);
}

/*	Converts an integer representation of a color (0xRRGGBB) into a
	t_color struct as defined in colors.h.
	Warning: Loss of precision will often occur due to nature of floating 
	point numbers.*/
t_color	rgb_itos(int i)
{
	t_color	c;

	c.red = itos((i >> 16) & 0xFF);
	c.green = itos((i >> 8) & 0xFF);
	c.blue = itos(i & 0xFF);
	return (c);
}

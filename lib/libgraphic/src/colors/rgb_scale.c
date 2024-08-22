/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:49:57 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 17:00:18 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/*	Returns the resulting t_color from multiplying 
	all elements of t_color c by the scalar s. */
t_color	rgb_scale(t_color c, float s)
{
	return ((t_color){c.red * s, c.green * s, c.blue * s});
}

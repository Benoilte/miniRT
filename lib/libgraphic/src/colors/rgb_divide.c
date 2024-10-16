/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_divide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:50:11 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/15 12:52:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/*	Returns the resulting t_color from dividing
	all elements of t_color c by the divisor d. */
t_color	rgb_divide(t_color c, float d)
{
	return ((t_color){c.red / d, c.green / d, c.blue / d});
}

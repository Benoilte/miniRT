/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:33:34 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/16 12:34:41 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

float	rgb_magnitude_squared(t_color c)
{
	return (fsquaref(c.red) + fsquaref(c.green) + fsquaref(c.blue));
}

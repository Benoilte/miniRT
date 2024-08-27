/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:29:25 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/27 15:33:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

bool	rgb_equal(t_color c1, t_color c2)
{
	return (equalf(c1.red, c2.red)
		&& equalf(c1.green, c2.green)
		&& equalf(c1.blue, c2.blue));
}

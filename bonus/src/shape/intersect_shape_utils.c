/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shape_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:58:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 15:58:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_swap(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

float	ft_get_max_f(float x, float y, float z)
{
	if ((equalf(fmaxf(x, y), x)) && (equalf(fmaxf(x, z), x)))
		return (x);
	if ((equalf(fmaxf(y, x), y)) && (equalf(fmaxf(y, z), y)))
		return (y);
	else
		return (z);
}

float	ft_get_min_f(float x, float y, float z)
{
	if ((equalf(fmaxf(x, y), y)) && (equalf(fmaxf(x, z), z)))
		return (x);
	if ((equalf(fmaxf(y, x), x)) && (equalf(fmaxf(y, z), z)))
		return (y);
	else
		return (z);
}

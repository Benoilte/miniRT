/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersect_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:57:28 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 11:07:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "float.h"

float	ft_get_min_or_max_float(float a)
{
	if (a < 0)
		return (FLT_MIN);
	else
		return (FLT_MAX);
}

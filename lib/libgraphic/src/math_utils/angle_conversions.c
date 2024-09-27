/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:02:40 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 14:02:54 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

float	deg_to_rad(float degrees)
{
	return (degrees / 180 * M_PI);
}

float	rad_to_deg(float radians)
{
	return (radians * 180 / M_PI);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:57:50 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 15:25:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

bool	equalf(float a, float b)
{
	return (fabsf(a - b) < EPSILON);
}

bool	lower_or_equalf(float a, float b)
{
	return ((a < b) || (fabsf(a - b) < EPSILON));
}

bool	greater_or_equalf(float a, float b)
{
	return ((a > b) || (fabsf(a - b) < EPSILON));
}

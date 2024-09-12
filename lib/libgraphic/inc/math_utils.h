/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:58:21 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 15:26:30 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

//	INCLUDES

# include <math.h>
# include <stdbool.h>

//	DEFINES

# define EPSILON	0.00001
# ifndef M_PI
#  define M_PI		3.14159265358979323846f
# endif

//	PROTOTYPES

bool	equalf(float a, float b);
bool	lower_or_equalf(float a, float b);
bool	greater_or_equalf(float a, float b);
float	fsquaref(float f);
float	deg_to_rad(float degrees);
float	rad_to_deg(float radians);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:15:56 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/15 12:52:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

//	INCLUDES

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "math_utils.h"

// DEFINES

# define RGB_INVALID_POINTER "invalid (null) rgb color pointer"

//	TYPEDEFS

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
}			t_color;

//	PROTOTYPES

t_color		*rgb_new(float red, float green, float blue);
t_color		rgb_set(float red, float green, float blue);
void		rgb_destroy(t_color	*color);
bool		rgb_equal(t_color c1, t_color c2);
int			rgb_stoi(t_color scalar);
t_color		rgb_itos(int color);
t_color		rgb_add(t_color c1, t_color c2);
t_color		rgb_sub(t_color c1, t_color c2);
t_color		rgb_scale(t_color c, float s);
t_color		rgb_mult(t_color a, t_color b);
t_color		rgb_divide(t_color c, float d);
t_color		rgb_blend(t_color a, t_color b, float weight);
void		rgb_error(const char *source, const char *msg);

#endif

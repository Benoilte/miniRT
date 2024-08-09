/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:15:56 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 16:58:53 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

//	INCLUDES
# include <math.h>

//	TYPEDEFS
typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
}			t_color;

//	PROTOTYPES

int			rgb_stoi(t_color scalar);
t_color		rgb_itos(int color);
t_color		rgb_add(t_color c1, t_color c2);
t_color		rgb_sub(t_color c1, t_color c2);
t_color		rgb_scale(t_color c, float s);
t_color		rgb_mult(t_color a, t_color b);
t_color		rgb_blend(t_color a, t_color b, float weight);

#endif
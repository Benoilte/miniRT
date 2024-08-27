/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:53:08 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/28 00:18:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

//	INCLUDES
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "math_utils.h"

//	DEFINES
# define VECTOR 	(0.0)
# define POINT		(1.0)

//	ERROR/WARNING MESSAGES
# define TP_ADD_ERROR	"resulting .w value is > 1"
# define TP_SUB_ERROR	"resulting .w value is < 0"
# define TP_DIV_ERROR	"divide by 0: returning unchanged tuple"
# define TP_MAG_ERROR	"applying magnitude to non-vector"
# define TP_NORM_ERROR1	"normalizing non-vector"
# define TP_NORM_ERROR2	"zero-magnitude vector: returning unchanged vector"
# define TP_DOT_ERROR	"calculating dot product for non-vector"
# define TP_CROSS_ERROR	"applying cross product to non-vector"

//	TYPEDEFS
typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}			t_tuple;

typedef t_tuple	t_vector;
typedef t_tuple	t_point;

//	PROTOTYPES
void		tp_error(const char *source, const char *msg);
t_tuple		vector(float x, float y, float z);
t_tuple		*alloc_vector(float x, float y, float z);
t_tuple		point(float x, float y, float z);
t_tuple		*alloc_point(float x, float y, float z);
bool		tp_equal(t_tuple a, t_tuple b);
t_tuple		tp_add(t_tuple a, t_tuple b);
t_tuple		tp_subtract(t_tuple a, t_tuple b);
t_tuple		tp_negate(t_tuple t);
t_tuple		tp_multiply(t_tuple a, float f);
t_tuple		tp_divide(t_tuple t, float d);
float		tp_magnitude(t_vector vec);
t_vector	tp_normalize(t_vector t);
float		tp_dot_product(t_vector a, t_vector b);
t_vector	tp_cross_product(t_vector a, t_vector b);
t_vector	tp_reflect(t_vector in, t_vector normal);

#endif

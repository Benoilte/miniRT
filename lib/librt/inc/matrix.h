/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:23:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/09 12:46:34 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

//	INCLUDES
# include "tuples.h"

//	DEFINES
# define MAX_MATRIX_SIZE (10000)
# define MAT4X4_SIZE (4)
# define MAT3X3_SIZE (3)
# define MAT2X2_SIZE (2)
# define X_AXIS (0)
# define Y_AXIS (1)
# define Z_AXIS (2)

//	ERROR/WARNING MESSAGES
# define MX_NULL_PTR_ERROR	"received NULL pointer: did not perform operation"
# define MX_INV_ERROR		"matrix determinant is 0: cannot invert matrix"
# define MX_AXIS_ERROR		"invalid axis: returning identity matrix"

//	TYPEDEFS
typedef struct s_m4x4
{
	float	data[MAT4X4_SIZE][MAT4X4_SIZE];
}				t_m4x4;

typedef struct s_m3x3
{
	float	data[MAT3X3_SIZE][MAT3X3_SIZE];
}			t_m3x3;

typedef struct s_m2x2
{
	float	data[MAT2X2_SIZE][MAT2X2_SIZE];
}			t_m2x2;

//	PROTOTYPES
void	mx_error(const char *source, const char *msg);
t_m4x4	mx_zero(void);
void	mx_bzero(t_m4x4 *m);
bool	mx_equal(t_m4x4 a, t_m4x4 b);
bool	mx_equal_3x3(t_m3x3 a, t_m3x3 b);
bool	mx_equal_2x2(t_m2x2 a, t_m2x2 b);
t_m4x4	mx_mult(t_m4x4 a, t_m4x4 b);

#endif
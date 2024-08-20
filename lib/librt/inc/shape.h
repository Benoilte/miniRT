/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:54:18 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/20 15:59:40 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "matrix.h"
# include "colors.h"
# include "sphere.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define SH_INVALID_TYPE "invalid shape type"
# define SH_INVALID_POINTER "invalid (null) shape pointer"
# define SH_VTABLE_ERROR "could not set shape vtable"

typedef enum e_shape_type
{
	SPHERE,
	SHAPE_COUNT
}	t_shape_type;

typedef struct s_shape_vtable
{
	void	(*set_default_shape)(t_shape *self);
	void	(*destroy)(void *self);
	bool	(*intersect)(t_ray *ray, t_shape *shape, t_intersect_report *report);
}			t_shape_vtable;

typedef struct s_shape
{
	t_shape_type			type;
	t_color					color;
	t_point					center;
	union
	{
		t_sphere			sphere;
	};
	t_m4x4					transform;
	const t_shape_vtable	*f;
}							t_shape;

void					shape_error(const char *source, const char *msg);
bool					invalid_shape_type(t_shape_type type);
void					destroy_shape(void *self);
const t_shape_vtable	*get_sphere_vtable(void);

#endif

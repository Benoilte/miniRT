/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:54:18 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/06 14:21:39 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

//	INCLUDES

# include "minirt.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

//	DEFINES

# define SH_INVALID_TYPE "invalid shape type"
# define SH_INVALID_POINTER "invalid (null) shape pointer"
# define SH_VTABLE_ERROR "could not set shape vtable"
# define SH_DEFAULT_COLOR 0xFFFFFF

# define MATERIAL_INVALID_POINTER "invalid (null) material pointer"

# define SPHERE_DEFAULT_X 0
# define SPHERE_DEFAULT_Y 0
# define SPHERE_DEFAULT_Z 0
# define SPHERE_DEFAULT_RADIUS 1

//	TYPEDEFS - forward declarations

typedef struct s_intersect_report	t_intersect_report;
typedef t_intersect_report			t_report;
typedef struct s_ray				t_ray;
typedef struct s_shape				t_shape;

// TYPEDEFS - MATERIAL

typedef struct s_material
{
	t_color	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

//	TYPEDEFS - SHPERE

typedef struct s_sphere
{
	float			radius;
	float			sq_radius;
}					t_sphere;

//	TYPEDEFS - SHAPES

typedef enum e_shape_type
{
	SPHERE,
	SHAPE_COUNT
}	t_shape_type;

typedef void						(*t_vset_default)(t_shape *self);
typedef void						(*t_vdestroy)(void *self);
typedef bool						(*t_vintersect)(t_ray *ray, t_shape *shape, t_report *report);
typedef t_vector					(*t_vnormal)(t_shape *shape, t_point *object_point);

typedef struct s_shape_vtable
{
	t_vset_default	set_default_shape;
	t_vdestroy		destroy;
	t_vintersect	intersect;
	t_vnormal		normal;
}			t_shape_vtable;

typedef struct s_shape
{
	t_shape_type			type;
	t_material				material;
	t_point					center;
	union
	{
		t_sphere			sphere;
	};
	t_m4x4					transform;
	t_m4x4					inverse;
	const t_shape_vtable	*f;
}							t_shape;

//	PROTOTYPES SHAPE
t_shape					*create_new_shape(t_shape_type type);
void					shape_error(const char *source, const char *msg);
bool					invalid_shape_type(t_shape_type type);
void					destroy_shape(void *self);
void					update_inverse(t_shape *shape);
void					set_default_material(t_material *m);
t_vector				get_normal(t_shape *shape, t_point world_point);

//	PROTOTYPES SPHERE
void					set_default_sphere(t_shape *self);
const t_shape_vtable	*get_sphere_vtable(void);
bool					intersect_sphere(t_ray *r, t_shape *shape, t_report *report);
t_vector				normal_sphere(t_shape *shape, t_point *object_point);

#endif

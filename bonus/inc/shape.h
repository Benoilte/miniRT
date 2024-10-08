/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:37 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/08 11:33:01 by bebrandt         ###   ########.fr       */
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

# define MATERIAL_INVALID_POINTER "invalid (null) material pointer"

# define PL_INSIDE_DEFAULT_OFSSET	0.00001f
# define CU_INSIDE_DEFAULT_OFSSET	0.00001f

# define SP_INSIDE_DEFAULT_OFSSET	0.00004f
# define CL_INSIDE_DEFAULT_OFSSET	0.00004f

// SPHERE CENTER DEFAULT

# define SPHERE_DEFAULT_X 0
# define SPHERE_DEFAULT_Y 0
# define SPHERE_DEFAULT_Z 0

// SPHERE RADIUS DEFAULT

# define SPHERE_DEFAULT_RADIUS 1

// PLANE CENTER DEFAULT

# define PLANE_DEFAULT_X 0
# define PLANE_DEFAULT_Y 0
# define PLANE_DEFAULT_Z 0

// CYLINDER CENTER DEFAULT

# define CL_DEFAULT_X 0
# define CL_DEFAULT_Y 0
# define CL_DEFAULT_Z 0

// CUBE CENTER DEFAULT

# define CU_DEFAULT_X 0
# define CU_DEFAULT_Y 0
# define CU_DEFAULT_Z 0

//	MATERIAL DEFAULTS

# define MAT_DEFAULT_COLOR			0xFFFFFF
# define MAT_DEFAULT_DIFFUSE		0.9f
# define MAT_DEFAULT_SPECULAR		0.9f
# define MAT_DEFAULT_SHININESS		200
# define MAT_DEFAULT_REFLECTIVE		0
# define MAT_DEFAULT_TRANSPARENCY	0
# define MAT_DEFAULT_REF_INDEX		1

// TYPEDEFS - MATERIAL

typedef struct s_material
{
	t_color	color;
	t_color	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
	float	reflective;
	float	transparency;
	float	refractive_index;
}			t_material;

//	TYPEDEFS - SHPERE

typedef struct s_sphere
{
	float			radius;
	float			sq_radius;
}					t_sphere;

//	TYPEDEFS - CYLINDER

typedef struct s_cylinder
{
	float			min;
	float			max;
	bool			closed;
}					t_cylinder;

//	TYPEDEFS - SHAPES

typedef enum e_shape_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CUBE,
	SHAPE_COUNT
}	t_shape_type;

typedef enum e_MIN_MAX
{
	MIN,
	MAX,
}	t_MIN_MAX;

typedef void		(*t_vset_default)(t_shape *self);
typedef void		(*t_vdestroy)(void *self);
typedef bool		(*t_vintersect)(t_ray *ray, \
									t_shape *shape, \
									t_report *report);
typedef t_vector	(*t_vnormal)(t_shape *shape, t_point *object_point);
typedef int			(*t_vset)(t_shape *self, char **args, t_world *world);

typedef struct s_vtable
{
	t_vset_default	set_default_shape;
	t_vset			set;
	t_vdestroy		destroy;
	t_vintersect	intersect;
	t_vnormal		normal;
}					t_vtable;

typedef struct s_shape
{
	t_shape_type			type;
	t_material				material;
	t_point					center;
	union
	{
		t_sphere			sphere;
		t_cylinder			cylinder;
	};
	t_m4x4					transform;
	t_m4x4					inverse;
	const t_vtable			*f;
}							t_shape;

//	PROTOTYPES SHAPE
t_shape			*create_new_shape(t_shape_type type);
void			shape_error(const char *source, const char *msg);
bool			invalid_shape_type(t_shape_type type);
void			destroy_shape(void *self);
void			update_inverse(t_shape *shape);
t_material		get_default_material(char **args);
t_vector		get_normal(t_shape *shape, t_point world_point);
t_list			*get_next_shape(t_list *tokens);
int				init_shapes(t_world *world, t_list *token_list);
t_m4x4			rotate_y_to(t_vector to);

//	PROTOTYPES SPHERE
int				set_sphere(t_shape *self, char **args, t_world *world);
void			set_default_sphere(t_shape *self);
const t_vtable	*get_sphere_vtable(void);
bool			intersect_sphere(t_ray *r, t_shape *shape, t_report *report);
t_vector		normal_sphere(t_shape *shape, t_point *object_point);

//	PROTOTYPES PLANE
int				set_plane(t_shape *self, char **args, t_world *world);
void			set_default_plane(t_shape *self);
const t_vtable	*get_plane_vtable(void);
bool			intersect_plane(t_ray *r, t_shape *shape, t_report *report);
t_vector		normal_plane(t_shape *shape, t_point *object_point);

//	PROTOTYPES CYLINDER
int				set_cylinder(t_shape *self, char **args, t_world *world);
void			set_default_cylinder(t_shape *self);
const t_vtable	*get_cylinder_vtable(void);
bool			intersect_cylinder(t_ray *ray, t_shape *cl, t_report *report);
bool			intersect_caps(t_ray *ray, t_shape *cl, t_report *report);
t_vector		normal_cylinder(t_shape *shape, t_point *object_point);

//	PROTOTYPES CUBE
int				set_cube(t_shape *self, char **args, t_world *world);
void			set_default_cube(t_shape *self);
const t_vtable	*get_cube_vtable(void);
bool			intersect_cube(t_ray *r, t_shape *shape, t_report *report);
t_vector		normal_cube(t_shape *shape, t_point *object_point);
float			ft_get_min_or_max_float(float a);

// PROTOTYPE INTERSECT SHAPE UTILS

void			ft_swap(float *a, float *b);

//	PROTOTYPES BONUS
void			set_shape_bonus(t_shape *self, char **args);

#endif

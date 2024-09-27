/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:54:18 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/27 16:23:02 by bebrandt         ###   ########.fr       */
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

// TYPEDEFS - MATERIAL

typedef struct s_material
{
	t_color	color;
	t_color	ambient;
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
	SHAPE_COUNT
}	t_shape_type;

typedef void		(*t_vset_default)(t_shape *self);
typedef void		(*t_vdestroy)(void *self);
typedef bool		(*t_vintersect)(t_ray *ray, \
									t_shape *shape, \
									t_report *report);
typedef t_vector	(*t_vnormal)(t_shape *shape, t_point *object_point);
typedef int			(*t_vset)(t_shape *self, char **args, t_color ambient);

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
void			set_default_material(t_material *m);
t_vector		get_normal(t_shape *shape, t_point world_point);
t_list			*get_next_shape(t_list *tokens);
int				init_shapes(t_world *world, t_list *token_list);
t_m4x4			rotate_y_to(t_vector to);

//	PROTOTYPES SPHERE
int				set_sphere(t_shape *self, char **args, t_color ambient);
void			set_default_sphere(t_shape *self);
const t_vtable	*get_sphere_vtable(void);
bool			intersect_sphere(t_ray *r, t_shape *shape, t_report *report);
t_vector		normal_sphere(t_shape *shape, t_point *object_point);

//	PROTOTYPES PLANE
int				set_plane(t_shape *self, char **args, t_color ambient);
void			set_default_plane(t_shape *self);
const t_vtable	*get_plane_vtable(void);
bool			intersect_plane(t_ray *r, t_shape *shape, t_report *report);
t_vector		normal_plane(t_shape *shape, t_point *object_point);

//	PROTOTYPES CYLINDER
int				set_cylinder(t_shape *self, char **args, t_color ambient);
void			set_default_cylinder(t_shape *self);
const t_vtable	*get_cylinder_vtable(void);
bool			intersect_cylinder(t_ray *ray, t_shape *cl, t_report *report);
bool			intersect_caps(t_ray *ray, t_shape *cl, t_report *report);
t_vector		normal_cylinder(t_shape *shape, t_point *object_point);

#endif

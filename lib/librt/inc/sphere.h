/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:17:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/21 16:11:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "shape.h"
# include "tuples.h"
# include "ray.h"
# include "intersection.h"

# define SPHERE_DEFAULT_X (0)
# define SPHERE_DEFAULT_Y (0)
# define SPHERE_DEFAULT_Z (0)
# define SPHERE_DEFAULT_COLOR (0xFFFFFF)
# define SPHERE_DEFAULT_RADIUS (1)

typedef struct s_shape	t_shape;

typedef struct s_sphere
{
	float			radius;
	float			sq_radius;
}					t_sphere;

void					set_default_sphere(t_shape *self);
const t_shape_vtable	*get_sphere_vtable(void);
bool					intersect_sphere(t_ray *r, t_shape *shape, t_intersect_report *report);

#endif

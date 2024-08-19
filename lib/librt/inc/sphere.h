/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:17:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/19 15:33:12 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "shape.h"
# include "tuples.h"
# include "ray.h"

# define SPHERE_DEFAULT_X (0)
# define SPHERE_DEFAULT_Y (0)
# define SPHERE_DEFAULT_Z (0)
# define SPHERE_DEFAULT_RED (0)
# define SPHERE_DEFAULT_GREEN (0)
# define SPHERE_DEFAULT_BLUE (0)
# define SPHERE_DEFAULT_RADIUS (1)

typedef struct s_shape	t_shape;

typedef struct s_sphere
{
	float			radius;
	float			sq_radius;
}					t_sphere;

void					set_default_sphere(t_shape *self);
const t_shape_vtable	*get_sphere_vtable(void);

#endif
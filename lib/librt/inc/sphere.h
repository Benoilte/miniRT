/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:17:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/16 16:24:52 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "tuples.h"
# include "ray.h"

typedef struct s_sphere_vtable
{
	bool	(*intersect)(t_ray *r, t_sphere *self);
	//		...
}	t_sphere_vtable;

typedef struct s_sphere
{
	t_point			center;
	float			radius;
	float			sq_radius;
	t_sphere_vtable	*f;
}					t_sphere;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:00:33 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/04 12:06:55 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

//	INCLUDES

# include "minirt.h"

//	TYPEDEFS

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}	t_ray;

//	PROTOTYPES

t_ray	ray(t_point	origin, t_vector direction);
t_point	ray_position(t_ray ray, float t);
t_ray	transform_ray(t_ray *r, t_m4x4 m);

#endif

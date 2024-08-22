/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:00:33 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/22 11:00:43 by bebrandt         ###   ########.fr       */
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

#endif

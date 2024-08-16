/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:00:33 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 16:07:34 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

//	INCLUDES

# include "tuples.h"

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
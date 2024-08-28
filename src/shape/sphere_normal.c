/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:33:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/28 21:47:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_vector	normal_sphere(t_shape *shape, t_point *object_point)
{
	return (tp_normalize(tp_subtract(*object_point, shape->center)));
}

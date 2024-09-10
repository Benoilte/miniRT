/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/10 16:25:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

// take the object_point and remove the y component.

t_vector	normal_cylinder(t_shape *shape, t_point *object_point)
{
	(void)shape;
	return (vector(object_point->x, 0, object_point->z));
}

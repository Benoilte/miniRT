/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:33:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/01 18:08:48 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normal_sphere(t_shape *shape, t_point *object_point)
{
	return (tp_normalize(tp_subtract(*object_point, shape->center)));
}

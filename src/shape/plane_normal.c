/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:53:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/09 16:17:02 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_vector	normal_plane(t_shape *shape, t_point *object_point)
{
    (void)object_point;
    (void)shape;
	return (vector(0, 1, 0));
}
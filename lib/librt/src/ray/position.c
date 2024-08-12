/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:03:43 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/12 16:07:09 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_point	ray_position(t_ray ray, float t)
{
	return (tp_add(ray.origin, tp_multiply(ray.direction, t)));
}

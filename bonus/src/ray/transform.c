/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:03:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/04 12:06:58 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	transform_ray(t_ray *r, t_m4x4 m)
{
	return (ray(mx_mult_tuple(m, r->origin), mx_mult_tuple(m, r->direction)));
}

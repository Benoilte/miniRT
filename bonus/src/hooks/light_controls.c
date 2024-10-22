/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:05:49 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/23 00:23:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	apply_light_control(int keycode, t_light *light, t_camera *camera)
{
	if (is_movement_key(keycode))
	{
		light->position = tp_add(light->position, \
						get_relative_movement(camera, get_direction(keycode)));
	}
}

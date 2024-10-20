/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:28:27 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/20 17:01:42 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	move_camera_origin(t_camera *camera, t_direction direction)
{
	t_vector	movement;

	movement = vector(0, 0, 0);
	if (direction == FORWARD)
		movement = camera->forward;
	else if (direction == BACK)
		movement = tp_negate(camera->forward);
	camera->from = tp_add(camera->from, movement);
}

void	apply_camera_control(int keycode, t_camera *camera)
{
	if (keycode == W_KEY)
		move_camera_origin(camera, FORWARD);
	else if (keycode == S_KEY)
		move_camera_origin(camera, BACK);
	camera->transform = view_transform(camera->from, camera->forward, camera->up);
	camera->transform_inverse = mx_inversion(camera->transform);
}

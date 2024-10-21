/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:28:27 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 21:25:26 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	move_camera_origin(t_camera *camera, t_direction direction)
{
	t_vector	movement;

	movement = vector(0, 0, 0);
	if (direction == FORWARD)
		movement = camera->forward;
	else if (direction == BACK)
		movement = tp_negate(camera->forward);
	else if (direction == LEFT)
		movement = tp_normalize(tp_cross_product(camera->forward, camera->up));
	else if (direction == RIGHT)
		movement = tp_normalize(tp_cross_product(camera->up, camera->forward));
	else if (direction == UP)
		movement = camera->up;
	else if (direction == DOWN)
		movement = tp_negate(camera->up);
	else
		return (print_error("move_camera_origin", "invalid direction"));
	camera->from = tp_add(camera->from, movement);
	return (0);
}

static int	tilt_camera(t_camera *cam, t_camera_rotate type)
{
	const float	angle = deg_to_rad(CAM_ROTATE_DEGREES);
	t_m4x4		rotate;

	if (type == PITCH_UP)
		rotate = mx_rodrigues_rotate(get_left(cam->forward, cam->up), angle);
	else if (type == PITCH_DOWN)
		rotate = mx_rodrigues_rotate(get_left(cam->forward, cam->up), -angle);
	else if (type == ROLL_RIGHT)
		rotate = mx_rodrigues_rotate(cam->forward, -angle);
	else if (type == ROLL_LEFT)
		rotate = mx_rodrigues_rotate(cam->forward, angle);
	else
		return (print_error("tilt_camera", "invalid rotate type"));
	cam->up = tp_normalize(mx_mult_tuple(rotate, cam->up));
	cam->forward = tp_normalize(mx_mult_tuple(rotate, cam->forward));
	return (0);
}

static int	spin_camera(t_camera *cam, t_camera_rotate type)
{
	const float	angle = deg_to_rad(CAM_ROTATE_DEGREES);
	t_m4x4		rotate;

	if (type == YAW_RIGHT)
		rotate = mx_rodrigues_rotate(cam->up, angle);
	else if (type == YAW_LEFT)
		rotate = mx_rodrigues_rotate(cam->up, -angle);
	else
		return (print_error("rotate_camemra", "invalid rotate type"));
	cam->forward = tp_normalize(mx_mult_tuple(rotate, cam->forward));
	return (0);
}

void	apply_camera_control(int keycode, t_camera *camera)
{
	if (is_movement_key(keycode))
		move_camera_origin(camera, get_direction(keycode));
	else if (is_rotation_key(keycode))
	{
		if (keycode == NP_FOUR || keycode == NP_SIX)
			spin_camera(camera, get_rotate_type(keycode));
		else
			tilt_camera(camera, get_rotate_type(keycode));
	}
	camera->transform = view_transform(camera);
	camera->transform_inverse = mx_inversion(camera->transform);
}

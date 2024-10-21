/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:28:27 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 15:54:46 by bgolding         ###   ########.fr       */
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
	else if (direction == LEFT)
		movement = tp_normalize(tp_cross_product(camera->forward, camera->up));
	else if (direction == RIGHT)
		movement = tp_normalize(tp_cross_product(camera->up, camera->forward));
	else if (direction == UP)
		movement = camera->up;
	else if (direction == DOWN)
		movement = tp_negate(camera->up);
	else
	{
		print_error("move_camera_origin", "invalid direction");
		return ;
	}
	camera->from = tp_add(camera->from, movement);
}

static void	rotate_camera(t_camera *cam, t_movement movement)
{
	const float	angle = deg_to_rad(15);
	t_m4x4		rotate;

	if (movement == YAW_RIGHT)
		rotate = mx_rodrigues_rotate(cam->up, angle);
	else if (movement == YAW_LEFT)
		rotate = mx_rodrigues_rotate(cam->up, -angle);
	else if (movement == PITCH_UP)
	{
		rotate = mx_rodrigues_rotate(get_left(cam->forward, cam->up), angle);
		cam->up = tp_normalize(mx_mult_tuple(rotate, cam->up));
	}
	else if (movement == PITCH_DOWN)
	{
		rotate = mx_rodrigues_rotate(get_left(cam->forward, cam->up), -angle);
		cam->up = tp_normalize(mx_mult_tuple(rotate, cam->up));
	}
	else
	{
		print_error("rotate_camemra", "invalid movement");
		return ;
	}
	cam->forward = tp_normalize(mx_mult_tuple(rotate, cam->forward));
}

void	apply_camera_control(int keycode, t_camera *camera)
{
	if (keycode == W_KEY)
		move_camera_origin(camera, FORWARD);
	else if (keycode == S_KEY)
		move_camera_origin(camera, BACK);
	else if (keycode == A_KEY)
		move_camera_origin(camera, LEFT);
	else if (keycode == D_KEY)
		move_camera_origin(camera, RIGHT);
	else if (keycode == Q_KEY)
		move_camera_origin(camera, DOWN);
	else if (keycode == E_KEY)
		move_camera_origin(camera, UP);
	else if (keycode == LEFT_KEY)
		rotate_camera(camera, YAW_LEFT);
	else if (keycode == RIGHT_KEY)
		rotate_camera(camera, YAW_RIGHT);
	else if (keycode == UP_KEY)
		rotate_camera(camera, PITCH_UP);
	else if (keycode == DOWN_KEY)
		rotate_camera(camera, PITCH_DOWN);
	camera->transform = view_transform(camera);
	camera->transform_inverse = mx_inversion(camera->transform);
}

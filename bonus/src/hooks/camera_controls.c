/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:28:27 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 18:46:28 by bgolding         ###   ########.fr       */
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

static int	tilt_camera(t_camera *cam, t_movement movement)
{
	const float	angle = deg_to_rad(CAM_ROTATE_DEGREES);
	t_m4x4		rotate;

	if (movement == PITCH_UP)
		rotate = mx_rodrigues_rotate(get_left(cam->forward, cam->up), angle);
	else if (movement == PITCH_DOWN)
		rotate = mx_rodrigues_rotate(get_left(cam->forward, cam->up), -angle);
	else if (movement == ROLL_RIGHT)
		rotate = mx_rodrigues_rotate(cam->forward, -angle);
	else if (movement == ROLL_LEFT)
		rotate = mx_rodrigues_rotate(cam->forward, angle);
	else
		return (print_error("rotate_camemra", "invalid movement"));
	cam->up = tp_normalize(mx_mult_tuple(rotate, cam->up));
	cam->forward = tp_normalize(mx_mult_tuple(rotate, cam->forward));
}

static int	spin_camera(t_camera *cam, t_movement movement)
{
	const float	angle = deg_to_rad(CAM_ROTATE_DEGREES);
	t_m4x4		rotate;

	if (movement == YAW_RIGHT)
		rotate = mx_rodrigues_rotate(cam->up, angle);
	else if (movement == YAW_LEFT)
		rotate = mx_rodrigues_rotate(cam->up, -angle);
	else
		return (print_error("rotate_camemra", "invalid movement"));
	cam->forward = tp_normalize(mx_mult_tuple(rotate, cam->forward));
	return (0);
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
	else if (keycode == NP_FOUR)
		spin_camera(camera, YAW_LEFT);
	else if (keycode == NP_SIX)
		spin_camera(camera, YAW_RIGHT);
	else if (keycode == NP_EIGHT)
		tilt_camera(camera, PITCH_UP);
	else if (keycode == NP_FIVE)
		tilt_camera(camera, PITCH_DOWN);
	else if (keycode == NP_SEVEN)
		tilt_camera(camera, ROLL_LEFT);
	else if (keycode == NP_NINE)
		tilt_camera(camera, ROLL_RIGHT);
	camera->transform = view_transform(camera);
	camera->transform_inverse = mx_inversion(camera->transform);
}

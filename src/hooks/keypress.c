/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:06:46 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/03 09:05:43 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_light_key(int keycode)
{
	if (keycode == LEFT_KEY || keycode == RIGHT_KEY || \
		keycode == UP_KEY || keycode == DOWN_KEY || \
		keycode == EQUAL_KEY || keycode == MINUS_KEY)
		return (true);
	return (false);
}

static bool	is_camera_key(int keycode)
{
	if (keycode == ONE_KEY || keycode == TWO_KEY || \
		keycode == W_KEY || keycode == S_KEY || \
		keycode == A_KEY || keycode == D_KEY)
		return (true);
	return (false);
}

void	move_camera(t_data *data, int keycode)
{
	static t_point	from = (t_point){0, 0, -5, POINT};
	const t_point to = point(0, 0, 0);
	const t_vector up = vector(0, 1, 0);

	if (keycode == A_KEY)
		from.x--;
	else if (keycode == D_KEY)
		from.x++;
	else if (keycode == W_KEY)
		from.y++;
	else if (keycode == S_KEY)
		from.y--;
	else if (keycode == ONE_KEY)
		from.z++;
	else if (keycode == TWO_KEY)
		from.z--;
	data->camera->transform = view_transform(from, to, up);
	data->camera->transform_inverse = mx_inversion(data->camera->transform);
}

void	move_light(t_light *light, int keycode)
{
	t_vector	move = vector(0, 0, 0);
	const float increment = 3;

	if (keycode == LEFT_KEY)
		move.x -= increment;
	else if (keycode == RIGHT_KEY)
		move.x += increment;
	else if (keycode == UP_KEY)
		move.y += increment;
	else if (keycode == DOWN_KEY)
		move.y -= increment;
	else if (keycode == EQUAL_KEY)
		move.z += increment;
	else if (keycode == MINUS_KEY)
		move.z -= increment;
	light->position = tp_add(light->position, move);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		return (close_minirt(data));
	if (data->world->light && is_light_key(keycode))
	{
		move_light(data->world->light, keycode);
		render(data);
	}
	if (is_camera_key(keycode))
	{
		move_camera(data, keycode);
		render(data);
	}
	return (0);
}

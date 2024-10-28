/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:18:11 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 21:40:34 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_movement_key(int key)
{
	return (key == W_KEY || key == S_KEY || key == A_KEY || \
			key == D_KEY || key == Q_KEY || key == E_KEY);
}

bool	is_rotation_key(int key)
{
	return (key == NP_FOUR || key == NP_SIX || key == NP_EIGHT || \
			key == NP_FIVE || key == NP_SEVEN || key == NP_NINE);
}

bool	is_control_key(int key)
{
	return (is_movement_key(key) || is_rotation_key(key));
}

t_direction	get_direction(int keycode)
{
	if (keycode == W_KEY)
		return (FORWARD);
	if (keycode == S_KEY)
		return (BACK);
	if (keycode == A_KEY)
		return (LEFT);
	if (keycode == D_KEY)
		return (RIGHT);
	if (keycode == Q_KEY)
		return (DOWN);
	if (keycode == E_KEY)
		return (UP);
	return (-1);
}

t_camera_rotate	get_rotate_type(int keycode)
{
	if (keycode == NP_FOUR)
		return (YAW_LEFT);
	if (keycode == NP_SIX)
		return (YAW_RIGHT);
	if (keycode == NP_EIGHT)
		return (PITCH_UP);
	if (keycode == NP_FIVE)
		return (PITCH_DOWN);
	if (keycode == NP_SEVEN)
		return (ROLL_LEFT);
	if (keycode == NP_NINE)
		return (ROLL_RIGHT);
	return (-1);
}

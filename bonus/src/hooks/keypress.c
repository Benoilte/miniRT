/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:06:46 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 17:14:57 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	apply_control(int keycode, t_data *data)
{
	int	mode;

	mode = get_mode();
	if (!mode)
		return (ft_printf("No mode selected for movement controls\n"));
	if (mode == MODE_CAMERA)
		apply_camera_control(keycode, data->camera);
	timed_render(data);
	return (0);
}

bool	is_control_key(int key)
{
	return (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY || \
		key == Q_KEY || key == E_KEY || key == LEFT_KEY || key == RIGHT_KEY);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		return (close_minirt(data));
	if (keycode == C_KEY)
	{
		toggle_mode(MODE_CAMERA);
		timed_render(data);
		return (0);
	}
	if (is_control_key(keycode))
		return (apply_control(keycode, data));
	return (0);
}

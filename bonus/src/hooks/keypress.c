/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:06:46 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 15:01:19 by bgolding         ###   ########.fr       */
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
	else if (mode == MODE_SHAPE_SELECT)
		if (apply_shape_control(keycode, data->camera) != 0)
			return (1);
	render(data);
	return (0);
}

int	switch_editor_mode(void)
{
	return (toggle_mode(get_mode() ^ TOGGLE_1_2));
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		return (close_minirt(data));
	if (editor_is(ON))
	{
		if (is_control_key(keycode))
			return (apply_control(keycode, data));
		if (keycode == TAB_KEY)
			return (switch_editor_mode());
		if (keycode == ENTER_KEY)
		{
			toggle_mode(get_mode());
			timed_render(data);
		}
	}
	else if (keycode == E_KEY)
	{
		toggle_mode(MODE_CAMERA);
		timed_render(data);
		return (0);
	}
	return (0);
}

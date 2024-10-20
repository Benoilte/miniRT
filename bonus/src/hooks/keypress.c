/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:06:46 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/20 16:26:18 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	*get_mode_ptr(void)
{
	static int	mode = MODE_BASE;

	return (&mode);
}

static int	get_mode(void)
{
	return (*get_mode_ptr());
}

static int	toggle_mode(t_control_mode toggle)
{
	*get_mode_ptr() &= toggle;
	return (0);
}

static void	apply_camera_control(int keycode, t_data *data)
{
	if (keycode == A_KEY)
		move_camera 
	else if (keycode == D_KEY)
}

static int	apply_control(int keycode, t_data *data)
{
	int	mode;

	mode = get_mode();
	if (!mode)
		return (print_error("keypress", "no mode selected"));
	if (mode == MODE_CAMERA)
		apply_camera_control(keycode, data);
	return (0);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		return (close_minirt(data));
	if (keycode == C_KEY)
		return (toggle_mode(MODE_CAMERA));
	if (is_control_key(keycode))
		return (apply_control(keycode, data));
	return (0);
}

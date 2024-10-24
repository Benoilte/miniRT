/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:11:53 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/23 11:00:59 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	*get_mode_ptr(void)
{
	static int	mode = MODE_BASE;

	return (&mode);
}

int	get_mode(void)
{
	return (*get_mode_ptr());
}

static void	print_mode_toggle(int previous_mode)
{
	const char	*control_modes[] = {"BASE", "CAMERA", "SHAPE SELECT", \
		"LIGHT", "RENDER_SETTINGS"};
	const int	new_mode = get_mode();

	if (new_mode == MODE_BASE)
	{
		printf("%s mode OFF\n", control_modes[previous_mode]);
		if (previous_mode >= MODE_CAMERA && previous_mode <= MODE_LIGHT)
			ft_printf("Exiting EDITOR mode\n");
	}
	else
		printf("%s mode ON\n", control_modes[new_mode]);
}

int	toggle_mode(int new_mode)
{
	int	previous_mode;

	previous_mode = get_mode();
	if (previous_mode == MODE_SHAPE_SELECT)
		set_selected_shape(NULL);
	if (previous_mode == new_mode)
		*get_mode_ptr() = MODE_BASE;
	else
		*get_mode_ptr() = new_mode;
	print_mode_toggle(previous_mode);
	return (0);
}

bool	editor_is(t_editor_value value)
{
	return ((get_mode() && (value == ON)) || (!get_mode() && (value == OFF)));
}

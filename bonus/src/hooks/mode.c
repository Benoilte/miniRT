/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:11:53 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 14:00:57 by bgolding         ###   ########.fr       */
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

static void	print_mode_toggle(void)
{
	const char	*control_modes[] = {"BASE", "CAMERA", "SHAPE SELECT", \
		"RENDER_SETTINGS", "LIGHT"};
	const int	mode = get_mode();

	if (mode)
		printf("%s mode ON\n", control_modes[mode]);
	else
		printf("%s mode OFF\n", control_modes[mode]);
}

int	toggle_mode(int toggle)
{
	int	mode;

	mode = get_mode();
	if (mode == toggle)
	{
		if (mode == MODE_SHAPE_SELECT)
			set_selected_shape(NULL);
		*get_mode_ptr() = MODE_BASE;
	}
	else
		*get_mode_ptr() = toggle;
	print_mode_toggle();
	return (0);
}

bool	editor_is(t_editor_value value)
{
	return ((get_mode() && (value == ON)) || (!get_mode() && (value == OFF)));
}

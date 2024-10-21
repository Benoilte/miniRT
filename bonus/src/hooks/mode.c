/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:11:53 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 16:56:57 by bebrandt         ###   ########.fr       */
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

static void	print_mode_toggle(t_control_mode toggle)
{
	const char	*control_modes[] = {"BASE", "CAMERA", "SHAPE", "LIGHT"};

	if (get_mode())
		printf("%s mode ON\n", control_modes[toggle]);
	else
		printf("%s mode OFF\n", control_modes[toggle]);
}

int	toggle_mode(int toggle)
{
	if (get_mode() == toggle)
		*get_mode_ptr() = MODE_BASE;
	else
		*get_mode_ptr() = toggle;
	print_mode_toggle(toggle);
	return (0);
}

bool	editor_is(t_editor_value value)
{
	return ((get_mode() && (value == ON)) || (!get_mode() && (value == OFF)));
}

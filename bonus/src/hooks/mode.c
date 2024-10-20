/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:11:53 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/20 17:12:57 by bgolding         ###   ########.fr       */
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

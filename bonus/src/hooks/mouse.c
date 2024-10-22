/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:39:23 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 09:58:15 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_down(int button, int x, int y, t_data *data)
{
	if (button != MOUSE_LEFT_CLICK)
		return (0);
	if (select_shape(x, y, data))
	{
		print_selected_shape();
		// toggle_mode(MODE_SHAPE);
		// timed_render(data);
	}
	else
		ft_printf("Click : No shape found\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:39:23 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 13:57:59 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_color(t_color c, char *msg);

void	print_selected_shape(void)
{
	t_shape	*shape;

	shape = get_selected_shape();
	if (!shape)
	{
		ft_printf("print selected shape : no shape\n");
		return ;
	}
	ft_printf("== SHAPE [%p] ==", shape);
	ft_printf("Type : %d\n", shape->type);
	print_color(shape->material.color, "Color");
}

int	mouse_down(int button, int x, int y, t_data *data)
{
	if (get_mode() != MODE_SHAPE_SELECT || button != MOUSE_LEFT_CLICK)
		return (0);
	if (select_shape(x, y, data))
	{
		print_selected_shape();
	}
	else
		ft_printf("Click : No shape found\n");
	return (0);
}

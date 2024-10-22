/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:39:23 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 18:55:55 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	stoi(float scalar)
{
	if (scalar >= 1.0f)
		return (255);
	if (scalar <= 0.0f)
		return (0);
	return (lrintf(scalar * 255.0));
}

static void	print_rgb(t_color c)
{
	printf("RGB [%d %d %d]\n", stoi(c.red), stoi(c.green), stoi(c.blue));
}

static void	print_selected_shape(void)
{
	const char	*shape_name[SHAPE_COUNT] = \
		{"SPHERE", "PLANE", "CYLINDER", "CUBE"};
	t_shape		*shape;

	shape = get_selected_shape();
	if (!shape || invalid_shape_type(shape->type))
		ft_printf("print_selected_shape : no shape or invalid shape\n");
	else
	{
		ft_printf("Selected : %s | ", shape_name[shape->type]);
		print_rgb(shape->material.color);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:17 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 17:55:47 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_tuple(t_tuple a, char *msg);

int	apply_shape_control(int keycode, t_camera *camera)
{
	t_shape		*shape;
	t_vector	movement;

	shape = get_selected_shape();
	if (!shape)
		return (ft_printf("No shape selected. Please click on a shape.\n"));
	if (is_movement_key(keycode))
	{
		movement = get_relative_movement(camera, get_direction(keycode));
		shape->f->move(shape, movement);
	}
	else
		return (ft_printf("Control not yet implemented (placeholder)\n"));
	return (0);
}

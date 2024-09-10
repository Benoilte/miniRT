/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 00:23:35 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 00:30:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_floor(t_data *data)
{
	t_shape		*floor;

	floor = create_new_shape(PLANE);
	if (!floor)
		return ;
	floor->material.color = rgb_set(1, 0.9, 0.9);
	floor->material.specular = 0;
	ft_lstadd_back(&data->world->shapes, ft_lstnew(floor));
}

static void	add_left_wall(t_data *data)
{
	t_shape		*left_w;

	left_w = create_new_shape(PLANE);
	if (!left_w)
		return ;
	left_w->transform = mx_add_rotation(left_w->transform, M_PI / 2, X_AXIS);
	left_w->transform = mx_add_rotation(left_w->transform, -M_PI / 4, Y_AXIS);
	left_w->transform = mx_add_translation(left_w->transform, 0, 0, 5);
	update_inverse(left_w);
	ft_lstadd_back(&data->world->shapes, ft_lstnew(left_w));
}

static void	add_right_wall(t_data *data)
{
	t_shape		*right_w;

	right_w = create_new_shape(PLANE);
	if (!right_w)
		return ;
	right_w->transform = mx_add_rotation(right_w->transform, M_PI / 2, X_AXIS);
	right_w->transform = mx_add_rotation(right_w->transform, M_PI / 4, Y_AXIS);
	right_w->transform = mx_add_translation(right_w->transform, 0, 0, 5);
	update_inverse(right_w);
	right_w->material.color = rgb_set(1, 0, 0);
	ft_lstadd_back(&data->world->shapes, ft_lstnew(right_w));
}

int	add_walls_and_floor(t_data *data)
{
	add_floor(data);
	add_left_wall(data);
	add_right_wall(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:55:03 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/09 17:07:25 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_floor(t_data *data)
{
	t_shape		*floor;

	floor = create_new_shape(PLANE);
	floor->material.color = rgb_set(1, 0.9, 0.9);
	floor->material.specular = 0;
	ft_lstadd_back(&data->world->shapes, ft_lstnew(floor));
}

static void	add_left_wall(t_data *data)
{
	t_shape		*left_w;

	left_w = create_new_shape(PLANE);
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
	right_w->transform = mx_add_rotation(right_w->transform, M_PI / 2, X_AXIS);
	right_w->transform = mx_add_rotation(right_w->transform, M_PI / 4, Y_AXIS);
	right_w->transform = mx_add_translation(right_w->transform, 0, 0, 5);
	update_inverse(right_w);
	right_w->material.color = rgb_set(1, 0, 0);
	ft_lstadd_back(&data->world->shapes, ft_lstnew(right_w));
}

static void	add_sp(t_data *data, t_m4x4 m, t_color color)
{
	t_shape		*sp;

	sp = create_new_shape(SPHERE);
	sp->transform = mx_mult(m, sp->transform);
	update_inverse(sp);
	sp->material.color = color;
	sp->material.diffuse = 0.7;
	sp->material.specular = 0.3;
	ft_lstadd_back(&data->world->shapes, ft_lstnew(sp));
}

void	set_first_scene_with_plane(t_data *data)
{
	add_floor(data);
	add_left_wall(data);
	add_right_wall(data);
	add_sp(data, \
		mx_translation(-0.5, 1, 0.5), \
		rgb_set(0.1, 1, 0.5));
	add_sp(data, \
		mx_mult(mx_translation(1.5, 0.5, -0.5), \
		mx_scaling(0.5, 0.5, 0.5)), \
		rgb_set(0.5, 1, 0.1));
	add_sp(data, \
		mx_mult(mx_translation(-1.5, 0.33, -0.75), \
		mx_scaling(0.33, 0.33, 0.33)), \
		rgb_set(1, 0.8, 0.1));
	data->camera->transform = view_transform(point(0, 1.5, -5), \
												point(0, 1, 0), \
												vector(0, 1, 0));
	data->camera->transform_inverse = mx_inversion(data->camera->transform);
}

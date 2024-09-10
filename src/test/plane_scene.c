/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:55:03 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 00:30:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_walls_and_floor(t_data *data);

static void	add_sp(t_data *data, t_m4x4 m, t_color color)
{
	t_shape		*sp;

	sp = create_new_shape(SPHERE);
	if (!sp)
		return ;
	sp->transform = mx_mult(m, sp->transform);
	update_inverse(sp);
	sp->material.color = color;
	sp->material.diffuse = 0.7;
	sp->material.specular = 0.3;
	ft_lstadd_back(&data->world->shapes, ft_lstnew(sp));
}

int	set_first_scene_with_plane(t_data *data)
{
	add_walls_and_floor(data);
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
	return (0);
}

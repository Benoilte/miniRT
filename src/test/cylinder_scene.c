/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:28:42 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 12:48:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_walls_and_floor(t_data *data);

static void	add_cl(t_data *data, t_m4x4 m, t_color color, float max)
{
	t_shape		*cl;

	cl = create_new_shape(CYLINDER);
	if (!cl)
		return ;
	cl->transform = mx_mult(m, cl->transform);
	update_inverse(cl);
	cl->cylinder.max = max;
	cl->material.color = color;
	cl->material.diffuse = 0.7;
	cl->material.specular = 0.3;
	ft_lstadd_back(&data->world->shapes, ft_lstnew(cl));
}

int	set_scene_with_cylinder(t_data *data)
{
	add_walls_and_floor(data);
	add_cl(data, \
		mx_translation(-0.5, 1, 0.5), \
		rgb_set(0.1, 1, 0.5), 1);
	add_cl(data, \
		mx_mult(mx_translation(1.5, 0.5, -0.5), \
		mx_scaling(0.5, 0.5, 0.5)), \
		rgb_set(0.5, 1, 0.1), 1);
	add_cl(data, \
		mx_mult(mx_translation(-2, 0.33, -0.75), \
		mx_scaling(0.33, 0.33, 0.33)), \
		rgb_set(1, 0.8, 0.1), 8);
	data->camera->transform = view_transform(point(0, 1.5, -5), \
												point(0, 1, 0), \
												vector(0, 1, 0));
	data->camera->transform_inverse = mx_inversion(data->camera->transform);
	return (0);
}

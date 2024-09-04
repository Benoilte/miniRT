/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:28:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/04 16:34:38 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_default_camera(t_camera *camera)
{
	t_point		from;
	t_point		to;
	t_vector	up;

	from = point(0, 0, -2);
	to = point(0, 0, 0);
	up = vector(0, 1, 0);
	camera->transform = view_transform(from, to, up);
	camera->transform_inverse = mx_inversion(camera->transform);
}

void	set_default_scene(t_data *data)
{
	set_default_camera(data->camera);
	add_new_shape_to_world(data->world, SPHERE);
}

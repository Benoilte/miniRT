/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:26:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/20 21:29:21 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	calibrate_camera(t_camera *c, t_pixel resolution)
{
	float	half_view;
	float	aspect_ratio;

	half_view = tan(c->field_of_view / 2);
	aspect_ratio = (float)resolution.x / (float)resolution.y;
	if (aspect_ratio >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect_ratio;
	}
	else
	{
		c->half_width = half_view * aspect_ratio;
		c->half_height = half_view;
	}
	c->pixel_size = (c->half_width * 2) / resolution.x;
}

t_camera	camera(t_pixel resolution, float fov)
{
	t_camera	camera;

	camera.field_of_view = fov;
	camera.transform = mx_identity();
	camera.transform_inverse = mx_identity();
	calibrate_camera(&camera, resolution);
	return (camera);
}

t_camera	*init_camera(t_data *data)
{
	char		**element;
	t_camera	*cam;

	if (!data)
		return (print_error("init_camera", INVALID_POINTER), NULL);
	element = get_element(data->input.token_list, ID_CAMERA);
	if (!element || count_args((const char **)element) != CAMERA_PARAMS + 1)
		return (print_error("init_camera", "Invalid camera element"), NULL);
	cam = ft_calloc(1, sizeof(t_camera));
	if (!cam)
		return (NULL);
	*cam = camera(data->resolution, deg_to_rad(ft_atod(element[3])));
	cam->from = str_to_tuple(element[1], POINT);
	cam->forward = tp_normalize(str_to_tuple(element[2], VECTOR));
	cam->up = vector(0, 1, 0);
	cam->transform = view_transform(cam);
	cam->transform_inverse = mx_inversion(cam->transform);
	return (cam);
}

void	destroy_camera(t_camera *camera)
{
	if (camera)
		free(camera);
}

t_ray	ray_for_pixel(t_camera c, t_pixel *pixel)
{
	t_point	world;
	t_point	pixel_point;
	t_ray	ray;

	world = point(\
		c.half_width - ((pixel->x + pixel->x_offset) * c.pixel_size), \
		c.half_height - ((pixel->y + pixel->y_offset) * c.pixel_size), -1);
	pixel_point = mx_mult_tuple(c.transform_inverse, world);
	ray.origin = mx_mult_tuple(c.transform_inverse, point(0, 0, 0));
	ray.direction = tp_normalize(tp_subtract(pixel_point, ray.origin));
	return (ray);
}

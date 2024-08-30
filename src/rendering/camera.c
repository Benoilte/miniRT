/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:26:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/30 15:36:40 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	calibrate_camera(t_camera *c)
{
	float	half_view;
	float	aspect_ratio;

	half_view = tan(c->field_of_view / 2);
	aspect_ratio = (float)c->hsize / (float)c->vsize;
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
	c->pixel_size = (c->half_width * 2) / c->hsize;
}

t_camera	camera(size_t hsize, size_t vsize, float fov)
{
	t_camera	camera;

	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.field_of_view = fov;
	camera.transform = mx_identity();
	camera.transform_inverse = mx_identity();
	calibrate_camera(&camera);
	return (camera);
}

t_ray	ray_for_pixel(t_camera c, size_t px, size_t py)
{
	t_point	world;
	t_point	pixel;
	t_ray	ray;

	world = point(\
		c.half_width - ((px + 0.5f) * c.pixel_size), \
		c.half_height - ((py + 0.5f) * c.pixel_size), -1);
	pixel = mx_mult_tuple(c.transform_inverse, world);
	ray.origin = mx_mult_tuple(c.transform_inverse, point(0, 0, 0));
	ray.direction = tp_normalize(tp_subtract(pixel, ray.origin));
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:02:05 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/14 20:20:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	get_px(t_color *color, t_render_info *info, t_pixel pixel)
{
	t_ray	ray;

	ray = ray_for_pixel(*(info->data->camera), pixel.x, pixel.y, pixel.x_offset, pixel.y_offset);
	if (color_at(color, NULL, &ray, info) != 0)
		return (print_error("get_px_small_res", THREAD_ERROR), 1);
	return (0);
}

static int	get_px_medium_res(t_color *color, t_render_info *info, t_pixel pixel)
{
	t_color	tmp_color;
	int		res;

	res = 4;
	if (get_px(color, info, pixel) != 0)
		return (print_error("get_px_medium_res", THREAD_ERROR), 1);
	while (res > 0)
	{
		if (get_px(&tmp_color, info, pixel) != 0)
			return (print_error("get_px_medium_res", THREAD_ERROR), 1);
		*color = rgb_add(tmp_color, *color);
		if ((pixel.x_offset + pixel.y_offset) == 0)
			pixel.x_offset++;
		else if ((pixel.x_offset + pixel.y_offset) == 2)
			pixel.x_offset--;
		else if (pixel.x_offset)
			pixel.y_offset++;
		res--;
	}
	// *color = rgb_scale(tmp_color, 1/5);
	color->red /= 5;
	color->green /= 5;
	color->blue /= 5;
	return (0);
}

/*
def sample_pixel(camera, x, y, samples_per_pixel=4):
    # Calculate how many samples along each dimension (n x n grid)
    sqrt_samples = int(math.sqrt(samples_per_pixel))

    colors = []

    # Loop through each sub-pixel sample
    for i in range(sqrt_samples):
        for j in range(sqrt_samples):
            # Calculate the fractional offset for each sample in the grid
            x_offset = (i + 0.5) / sqrt_samples
            y_offset = (j + 0.5) / sqrt_samples
            
            # Generate a ray for this sub-pixel sample
            ray = ray_for_pixel(camera, x, y, x_offset, y_offset)

            # Trace the ray to get the color (trace_ray is a placeholder for your ray tracer function)
            color = trace_ray(ray)
            colors.append(color)

    # Average the colors from all samples
    return average_colors(colors)
*/

static int	get_px_big_res(t_color *color, t_render_info *info, t_pixel pixel, int res)
{
	t_color	tmp_color;
	int		i;
	int		j;

	*color = rgb_set(0, 0, 0);
	i = 0;
	while (i < res)
	{
		j = 0;
		while (j < res)
		{
			pixel.x_offset = (i + 0.5) / res;
			pixel.y_offset = (j + 0.5) / res;
			if (get_px(&tmp_color, info, pixel) != 0)
				return (print_error("get_px_medium_res", THREAD_ERROR), 1);
			*color = rgb_add(tmp_color, *color);
			j++;
		}
		i++;
	}
	color->red /= (res * res);
	color->green /= (res * res);
	color->blue /= (res * res);
	return (0);
}

int	render_pixel(t_color *color, t_render_info *info, t_pixel pixel, size_t res)
{
	if (res == 1)
	{
		pixel.x_offset = 0.5;
		pixel.y_offset = 0.5;
		if (get_px(color, info, pixel) != 0)
			return (print_error("render_pixel", THREAD_ERROR), 1);
	}
	else if (res == 2)
	{
		pixel.x_offset = 0;
		pixel.y_offset = 0;
		if (get_px_medium_res(color, info, pixel) != 0)
			return (print_error("render_pixel", THREAD_ERROR), 1);
	}
	else if (res == 3)
	{
		pixel.x_offset = 0;
		pixel.y_offset = 0;
		if (get_px_big_res(color, info, pixel, 3) != 0)
			return (print_error("render_pixel", THREAD_ERROR), 1);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:41:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/26 17:37:01 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

static t_color	compute_diffuse(	t_details *details, \
									t_color effective, \
									t_vector lightv)
{
	float	light_dot_normal;

	light_dot_normal = tp_dot_product(lightv, details->normalv);
	if (light_dot_normal < 0)
		return (rgb_set(0, 0, 0));
	else
	{
		return (rgb_scale(effective, \
				details->shape->material.diffuse * light_dot_normal));
	}
}

static t_color	compute_specular(	t_details *details, \
									t_light *light, \
									t_vector lightv)
{
	t_vector	reflectv;
	float		reflect_dot_eye;
	float		factor;

	reflectv = tp_reflect(tp_negate(lightv), details->normalv);
	reflect_dot_eye = tp_dot_product(reflectv, details->eyev);
	if (reflect_dot_eye <= 0)
		return (rgb_set(0, 0, 0));
	else
	{
		factor = powf(reflect_dot_eye, details->shape->material.shininess);
		factor *= details->shape->material.specular;
		return (rgb_scale(light->intensity, factor));
	}
}

t_color	lighting(t_details *details, t_light *light, t_light *ambiant_light)
{
	t_color		effective;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_vector	lightv;

	ambient = rgb_mult(details->shape->material.color, \
						ambiant_light->intensity);
	if (details->in_shadow)
		return (ambient);
	lightv = tp_normalize(tp_subtract(light->position, details->position));
	effective = rgb_mult(details->shape->material.color, light->intensity);
	diffuse = compute_diffuse(details, effective, lightv);
	specular = compute_specular(details, light, lightv);
	return (rgb_add(rgb_add(ambient, diffuse), specular));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:41:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/30 17:37:33 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

static t_color	compute_ambient(t_intersect_details *details, t_color effective_color)
{
	return (rgb_scale(effective_color, details->shape->material.ambient));
}

static t_color	compute_diffuse(t_intersect_details *details, t_color effective, t_vector lightv)
{
	float		light_dot_normal;

	light_dot_normal = tp_dot_product(lightv, details->normalv);
	if (light_dot_normal < 0)
		return (rgb_set(0, 0, 0));
	else
		return (rgb_scale(effective, details->shape->material.diffuse * light_dot_normal));
}

static t_color	compute_specular(t_intersect_details *details, t_light *light, t_vector lightv)
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
		return (rgb_scale(light->intensity, details->shape->material.specular * factor));
	}
}

t_color	lighting(t_intersect_details *details, t_light *light)
{
	t_color		effective_color;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_vector	lightv;

	lightv = tp_normalize(tp_subtract(light->position, details->position));
	effective_color = rgb_mult(details->shape->material.color, light->intensity);
	ambient = compute_ambient(details, effective_color);
	diffuse = compute_diffuse(details, effective_color, lightv);
	specular = compute_specular(details, light, lightv);
	return (rgb_add(rgb_add(ambient, diffuse), specular));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:38:39 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/11 12:28:51 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	no_color(void)
{
	const t_color	black = rgb_set(0, 0, 0);

	return (black);
}

/*
»	  reflected ← reflected_color(world, comps, remaining)
»	  refracted ← refracted_color(world, comps, remaining)
»
»	  material ← comps.object.material
»	  ​if​ material.reflective > 0 ​&&​ material.transparency > 0
»	    reflectance ← schlick(comps)
»	    ​return​ surface + reflected * reflectance +
»	                     refracted * (1 - reflectance)
»	  ​else​
»	    ​return​ surface + reflected + refracted
»	  ​end​
​ 	​end​ ​function
*/

int	compute_final_color(t_color *color, \
						t_details *details, \
						t_render_info info, \
						t_inter_lst *intersects)
{
	t_color		surface;
	t_color		reflected;
	t_color		refracted;
	t_material	material;
	float		reflectance;

	if (!color || !details)
		return (print_error("compute_final_color", INVALID_POINTER));
	if (set_shadow(info.data->world, details) != 0)
		return (1);
	surface = lighting(details, info.data->world->light);
	if (refracted_color(&refracted, info, details, intersects) != 0)
		return (2);
	if (reflected_color(&reflected, info, details) != 0)
		return (2);
	material = details->shape->material;
	if ((material.reflective > 0) && (material.transparency > 0) && (info.depth == 0))
	{
		reflectance = schlick_approximation(details);
		*color = rgb_add(rgb_add(surface, rgb_scale(reflected, reflectance)), rgb_scale(refracted, 1 - reflectance));
	}
	else
		*color = rgb_add(rgb_add(surface, reflected), refracted);
	return (0);
}

int	color_at(t_color *color, t_shape *self, t_ray *ray, t_render_info *info)
{
	t_intersect_list	*intersects;
	t_intersect_list	*hit;
	t_details			details;

	if (!ray || !info)
		return (print_error("color_at", INVALID_POINTER));
	ft_bzero(&details, sizeof(details));
	intersects = NULL;
	if (intersect_world(&intersects, ray, info->data->world) != 0)
		return (2);
	hit = get_first_hit(&intersects);
	if (self != NULL)
		set_first_hit_valid(self, &hit);
	if (!hit)
		*color = no_color();
	else
	{
		if ((compute_details(&details, &hit->intersect, *ray))
			|| (compute_final_color(color, &details, *info, intersects)))
			return (inter_lstclear(&intersects), 3);
	}
	inter_lstclear(&intersects);
	return (0);
}

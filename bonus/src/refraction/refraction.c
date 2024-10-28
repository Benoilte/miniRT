/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:17:18 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/21 11:48:16 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	compute_snell_law(t_details *details, \
								float *n_ratio, \
								float *cos_i, \
								float *cos_t)
{
	float	sin2_t;

	*n_ratio = details->n1 / details->n2;
	*cos_i = tp_dot_product(details->eyev, details->normalv);
	sin2_t = powf(*n_ratio, 2) * (1 - powf(*cos_i, 2));
	if (sin2_t > 1)
		return (0);
	*cos_t = sqrtf(1 - sin2_t);
	return (1);
}

static t_ray	compute_refracted_ray(t_details *details, \
									float n_ratio, \
									float cos_i, \
									float cos_t)
{
	t_vector	direction;

	set_under_point(details);
	direction = tp_subtract(tp_multiply(details->normalv, \
				(n_ratio * cos_i - cos_t)), \
				tp_multiply(details->eyev, n_ratio));
	return (ray(details->under_point, direction));
}

int	refracted_color(t_color *color, \
					t_render_info info, \
					t_details *details, \
					t_inter_lst *intersects)
{
	t_ray		refracted_ray;
	float		n_ratio;
	float		cos_i;
	float		cos_t;

	if (equalf(details->shape->material.transparency, 0)
		|| (info.refractive_depth <= 0))
	{
		*color = rgb_set(0, 0, 0);
		return (0);
	}
	compute_refraction_indices(intersects, details, info.shape_container);
	if (compute_snell_law(details, &n_ratio, &cos_i, &cos_t) == 0)
	{
		*color = rgb_set(0, 0, 0);
		return (0);
	}
	refracted_ray = compute_refracted_ray(details, n_ratio, cos_i, cos_t);
	info.refractive_depth--;
	info.depth++;
	if (color_at(color, NULL, &refracted_ray, &info) != 0)
		return (1);
	*color = rgb_scale(*color, details->shape->material.transparency);
	return (0);
}

void	compute_refraction_indices(	t_inter_lst *intersects, \
									t_details *details, \
									t_dbl_lst *containers)
{
	t_inter_lst	*tmp;

	tmp = intersects;
	reset_shape_container(containers);
	while (tmp)
	{
		if (equalf(tmp->intersect.t, details->t))
		{
			details->n1 = get_last_refraction_index(containers);
			move_shape(tmp->intersect.shape, &containers);
			details->n2 = get_last_refraction_index(containers);
			break ;
		}
		else
			move_shape(tmp->intersect.shape, &containers);
		tmp = tmp->next;
	}
}

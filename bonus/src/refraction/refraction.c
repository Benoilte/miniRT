/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:17:18 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 10:29:23 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
If the intersection is the hit, set n1 to the refractive index of the last
object in the containers list. If that list is empty,
then there is no containing object, and n1 should be set to 1.

If the intersection’s object is already in the containers list,
then this intersection must be exiting the object.
Remove the object from the containers list in this case.
Otherwise, the intersection is entering the object,
and the object should be added to the end of the list.

If the intersection is the hit, set n2 to the refractive index
of the last object in the containers list. If that list is empty, then again,
there is no containing object and n2 should be set to 1.

If the intersection is the hit, terminate the loop here.
*/

/*
​ 	​# Find the ratio of first index of refraction to the second.​
​ 	​# (Yup, this is inverted from the definition of Snell's Law.)​
​ 	n_ratio ← comps.n1 / comps.n2
​
​ 	​# cos(theta_i) is the same as the dot product of the two vectors​
​ 	cos_i ← dot(comps.eyev, comps.normalv)
​
​ 	​# Find sin(theta_t)^2 via trigonometric identity​
​ 	sin2_t ← n_ratio​^​2 * (1 - cos_i​^​2)

​ 	​# Find cos(theta_t) via trigonometric identity​
​ 	cos_t ← sqrt(1.0 - sin2_t)
​
​ 	​# Compute the direction of the refracted ray​
​ 	direction ← comps.normalv * (n_ratio * cos_i - cos_t) -
​ 	             comps.eyev * n_ratio
​
​ 	​# Create the refracted ray​
​ 	refract_ray ← ray(comps.under_point, direction)
​
​ 	​# Find the color of the refracted ray, making sure to multiply​
​ 	​# by the transparency value to account for any opacity​
​ 	color ← color_at(world, refract_ray, remaining - 1) *
​ 	         comps.object.material.transparency
*/

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
					t_dbl_lst *intersects)
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
	if (color_at(color, NULL, &refracted_ray, &info) != 0)
		return (1);
	*color = rgb_scale(*color, details->shape->material.transparency);
	return (0);
}

void	compute_refraction_indices(	t_dbl_lst *intersects, \
									t_details *details, \
									t_dbl_lst *containers)
{
	t_dbl_lst	*tmp;

	tmp = intersects;
	reset_shape_container(containers);
	while (tmp)
	{
		if (equalf(((t_intersection *)tmp->content)->t, details->t))
		{
			details->n1 = get_last_refraction_index(containers);
			move_shape(((t_intersection *)tmp->content)->shape, &containers);
			details->n2 = get_last_refraction_index(containers);
			break ;
		}
		else
			move_shape(((t_intersection *)tmp->content)->shape, &containers);
		tmp = tmp->next;
	}
}

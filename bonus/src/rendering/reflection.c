/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:18:57 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/10 18:16:33 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
​ 	​function​ schlick(comps)
​ 	  ​# find the cosine of the angle between the eye and normal vectors​
​ 	  cos ← dot(comps.eyev, comps.normalv)
​ 	
​ 	  ​# total internal reflection can only occur if n1 > n2​
​ 	  ​if​ comps.n1 > comps.n2
​ 	    n ← comps.n1 / comps.n2
​ 	    sin2_t = n​^​2 * (1.0 - cos​^​2)
​ 	    ​return​ 1.0 ​if​ sin2_t > 1.0
​ 	  ​end​ ​if​
​ 	
​ 	  ​# return anything but 1.0 here, so that the test will fail​
​ 	  ​# appropriately if something goes wrong.​
​ 	  ​return​ 0.0
​ 	​end​ ​function
*/

/*
​ 	​function​ schlick(comps)
​ 	  ​# find the cosine of the angle between the eye and normal vectors​
​ 	  cos ← dot(comps.eyev, comps.normalv)
​ 	
​ 	  ​# total internal reflection can only occur if n1 > n2​
​ 	  ​if​ comps.n1 > comps.n2
​ 	    n ← comps.n1 / comps.n2
​ 	    sin2_t = n​^​2 * (1.0 - cos​^​2)
​ 	    ​return​ 1.0 ​if​ sin2_t > 1.0
​ 	
»	    ​# compute cosine of theta_t using trig identity​
»	    cos_t ← sqrt(1.0 - sin2_t)
»	
»	    ​# when n1 > n2, use cos(theta_t) instead​
»	    cos ← cos_t
​ 	  ​end​ ​if​
​ 	
»	  r0 ← ((comps.n1 - comps.n2) / (comps.n1 + comps.n2))​^​2
»	  ​return​ r0 + (1 - r0) * (1 - cos)​^​5
​ 	​end​ ​function
*/

float	schlick_approximation(t_details *details)
{
	float	cos;
	float	n;
	float	sin2_t;
	float	approximation;

	if (equalf(details->shape->material.transparency, 0))
		return (0);
	cos = tp_dot_product(details->eyev, details->normalv);
	if (details->n1 > details->n2)
	{
		n = details->n1 / details->n2;
		sin2_t = powf(n, 2) * (1 - powf(cos, 2));
		if (sin2_t > 1.0)
			return (1);
		cos =sqrtf(1 - sin2_t);
	}
	approximation = powf(((details->n1 - details->n2) / (details->n1 + details->n2)), 2);
	return (approximation + ((1 - approximation) * powf((1 - cos), 5)));
}

int	reflected_color(t_color *color, t_render_info info, t_details *details)
{
	t_ray	reflect_ray;

	if (equalf(details->shape->material.reflective, 0)
		|| (info.reflective_depth <= 0))
	{
		*color = rgb_set(0, 0, 0);
		return (0);
	}
	reflect_ray = ray(details->over_point, details->reflectv);
	info.reflective_depth--;
	if (color_at(color, details->shape, &reflect_ray, &info) != 0)
		return (1);
	*color = rgb_scale(*color, details->shape->material.reflective);
	return (0);
}

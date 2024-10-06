/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_and_refraction_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:41:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/06 09:00:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
​ 	​Scenario​: The refracted color with an opaque surface
​ 	  ​Given​ w ← default_world()
​ 	    ​And​ shape ← the first object in w
​ 	    ​And​ r ← ray(point(0, 0, -5), vector(0, 0, 1))
​ 	    ​And​ xs ← intersections(4:shape, 6:shape)
​ 	  ​When​ comps ← prepare_computations(xs[0], r, xs)
​ 	    ​And​ c ← refracted_color(w, comps, 5)
​ 	  ​Then​ c = color(0, 0, 0)
*/

void	test_refracted_color_return_black(t_data *data)
{
	t_ray				r1;
	t_intersect_list	*intersects;
	t_details			details;
	t_color				color;

	r1 = ray(point(0, 0, -5), vector(0, 0, 1));
	ft_bzero(&details, sizeof(details));
	intersects = NULL;
	if (intersect_world(&intersects, &r1, data->world) != 0)
		return ;
	compute_details(&details, get_first_hit(&intersects)->content, r1);
	refracted_color(&color, &data->render[0], &details, intersects);
	printf("check if The refracted color with an opaque surface\n");
	if (rgb_equal(color, rgb_set(0, 0, 0)))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	dbl_lstclear(&intersects, clear_intersection);
}

/*
​ 	​Scenario​: The refracted color under total internal reflection
​ 	  ​Given​ w ← default_world()
​ 	    ​And​ shape ← the first object in w
​ 	    ​And​ shape has:
​ 	      | material.transparency     | 1.0 |
​ 	      | material.refractive_index | 1.5 |
​ 	    ​And​ r ← ray(point(0, 0, √2/2), vector(0, 1, 0))
​ 	    ​And​ xs ← intersections(-√2/2:shape, √2/2:shape)
​ 	  ​# NOTE: this time you're inside the sphere, so you need​
​ 	  ​# to look at the second intersection, xs[1], not xs[0]​
​ 	  ​When​ comps ← prepare_computations(xs[1], r, xs)
​ 	    ​And​ c ← refracted_color(w, comps, 5)
​ 	  ​Then​ c = color(0, 0, 0)
*/

void	test_refracted_under_total_internal_reflection(t_data *data)
{
	t_ray				r1;
	t_intersect_list	*intersects;
	t_details			details;
	t_color				color;

	r1 = ray(point(0, 0, sqrtf(2) / 2), vector(0, 1, 0));
	ft_bzero(&details, sizeof(details));
	intersects = NULL;
	if (intersect_world(&intersects, &r1, data->world) != 0)
		return ;
	compute_details(&details, get_first_hit(&intersects)->content, r1);
	refracted_color(&color, &data->render[0], &details, intersects);
	printf("check, refracted color under total internal reflection is black\n");
	if (rgb_equal(color, rgb_set(0, 0, 0)))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	dbl_lstclear(&intersects, clear_intersection);
}

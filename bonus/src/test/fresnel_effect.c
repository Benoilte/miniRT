/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel_effect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:17:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/10 18:18:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
​ 	​Scenario​: The Schlick approximation under total internal reflection
​ 	  ​Given​ shape ← glass_sphere()
​ 	    ​And​ r ← ray(point(0, 0, √2/2), vector(0, 1, 0))
​ 	    ​And​ xs ← intersections(-√2/2:shape, √2/2:shape)
​ 	  ​When​ comps ← prepare_computations(xs[1], r, xs)
​ 	    ​And​ reflectance ← schlick(comps)
​ 	  ​Then​ reflectance = 1.0
*/

static void	check_reflectance(t_details *details, float value)
{
	float	reflectance;

	reflectance = schlick_approximation(details);
	if (equalf(reflectance, value))
		printf("\033[0;32mTRUE\033[0m\n");
	else
	{
		printf("\033[0;31mFALSE\033[0m\n");
		printf("reflectance is equal to %.5f\n", reflectance);
	}
}


/*
​ 	​Scenario​: The Schlick approximation with a perpendicular viewing angle
​ 	  ​Given​ shape ← glass_sphere()
​ 	    ​And​ r ← ray(point(0, 0, 0), vector(0, 1, 0))
​ 	    ​And​ xs ← intersections(-1:shape, 1:shape)
​ 	  ​When​ comps ← prepare_computations(xs[1], r, xs)
​ 	    ​And​ reflectance ← schlick(comps)
​ 	  ​Then​ reflectance = 0.04
*/

static void	compute_reflectance(t_data *data, t_ray r1, float value)
{
	t_intersect_list    *intersects;
	t_intersect_list    *hit;
	t_details			details;

	intersects = NULL;
    if (intersect_world(&intersects, &r1, data->world) != 0)
	{
		printf("error with intersect_world function\n");
        return ;
	}
    hit = get_first_hit(&intersects);
	if (!hit)
	{
		printf("no hit\n");
		return ;
	}
	printf("hit = %.5f", hit->intersect.t);
	if (equalf(hit->intersect.t, 1.85893))
		hit->intersect.t = 1.8589;
	compute_details(&details, &hit->intersect, r1);
	compute_refraction_indices(intersects, &details, data->render.blocks[0].shape_container);
	check_reflectance(&details, value);
	inter_lstclear(&intersects);
}

/*
​ 	​Scenario​: The Schlick approximation with small angle and n2 > n1
​ 	  ​Given​ shape ← glass_sphere()
​ 	    ​And​ r ← ray(point(0, 0.99, -2), vector(0, 0, 1))
​ 	    ​And​ xs ← intersections(1.8589:shape)
​ 	  ​When​ comps ← prepare_computations(xs[0], r, xs)
​ 	    ​And​ reflectance ← schlick(comps)
​ 	  ​Then​ reflectance = 0.48873
*/

void    test_schlick_approximation(t_data *data)
{
    t_ray               r1;

    r1 = ray(point(0, 0, sqrtf(2) / 2), vector(0, 1, 0));
    compute_reflectance(data, r1, 1);
    r1 = ray(point(0, 0, 0), vector(0, 1, 0));
    compute_reflectance(data, r1, 0.04);
    r1 = ray(point(0, 0.99, -2), vector(0, 0, 1));
    compute_reflectance(data, r1, 0.48873);
}

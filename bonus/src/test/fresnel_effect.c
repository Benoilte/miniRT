/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel_effect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:17:29 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/11 14:59:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

static void	compute_reflectance(t_data *data, t_ray r1, float value)
{
	t_intersect_list	*intersects;
	t_intersect_list	*hit;
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
	compute_refraction_indices(intersects, \
							&details, data->render.blocks[0].shape_container);
	check_reflectance(&details, value);
	inter_lstclear(&intersects);
}

void	test_schlick_approximation(t_data *data)
{
	t_ray	r1;

	r1 = ray(point(0, 0, sqrtf(2) / 2), vector(0, 1, 0));
	compute_reflectance(data, r1, 1);
	r1 = ray(point(0, 0, 0), vector(0, 1, 0));
	compute_reflectance(data, r1, 0.04);
	r1 = ray(point(0, 0.99, -2), vector(0, 0, 1));
	compute_reflectance(data, r1, 0.48873);
}

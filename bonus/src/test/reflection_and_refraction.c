/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_and_refraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:28:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/30 11:36:28 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_reflective_value(t_world *world)
{
	printf("check if reflective value is equal to 0,0\n");
	if (equalf(((t_shape *)(world->shapes->content))->material.reflective, 0.0))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
}

void	test_reflective_vector(t_world *world)
{
	t_shape			*shape;
	t_intersection	inter;
	t_details		details;
	t_ray			r1;

	shape = create_new_shape(PLANE);
	if (!shape)
		return ;
	r1 = ray(point(0, 1, -1), vector(0, -(sqrtf(2)) / 2, (sqrtf(2)) / 2));
	inter = set_intersection(shape, sqrtf(2));
	if (compute_details(&details, &inter, r1, world) != 0)
	{
		destroy_shape(shape);
		return ;
	}
	printf("check if reflective vector is equal to vector(0, √2/2, √2/2)\n");
	if (tp_equal(details.reflectv, vector(0, sqrtf(2) / 2, sqrtf(2) / 2)))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	destroy_shape(shape);
}

void	test_non_rflective_material(t_world *world)
{
	t_ray			r1;
	t_shape			*shape;
	t_intersection	inter;
	t_details		details;
	t_color			color;

	r1 = ray(point(0, 0, 0), vector(0, 0, 1));
	shape = ((t_shape *)(world->shapes->content));
	inter = set_intersection(shape, 1);
	if (compute_details(&details, &inter, r1, world) != 0)
		return ;
	color = reflected_color(world, &details);
	printf("check if non reflective material return a black color\n");
	if (rgb_equal(color, rgb_set(0, 0, 0)))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
}

// test_reflective_material(t_world *world)
// {
	
// }

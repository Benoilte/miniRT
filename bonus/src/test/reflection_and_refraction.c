/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_and_refraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:28:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/30 16:26:07 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_color(t_color c, char *msg);

void	test_reflective_value(t_world *world, float value)
{
	t_shape	*shape;
	
	shape = ((t_shape *)(world->shapes->next->content));
	printf("check if reflective value is equal to %f\n", value);
	if (equalf(shape->material.reflective, value))
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

void	test_non_reflective_material(t_world *world)
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
	if (reflected_color(&color, world, &details) != 0)
		return ;
	printf("check if non reflective material return a black color\n");
	if (rgb_equal(color, rgb_set(0, 0, 0)))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
}

void	test_reflective_material(t_world *world)
{
	t_ray			r1;
	t_shape			*shape;
	t_intersection	inter;
	t_details		details;
	t_color			color;

	shape = ((t_shape *)(world->shapes->next->content));
	shape->material.reflective = 0.5;
	r1 = ray(point(0, 0, -3), vector(0, -(sqrtf(2)) / 2, (sqrtf(2)) / 2));
	inter = set_intersection(shape, sqrtf(2));
	if (compute_details(&details, &inter, r1, world) != 0)
		return ;
	if (color_at(&color, &r1, world) != 0)
		return ;
	printf("check if reflective material return a color(0, 0.67726, 0)\n");
	if (rgb_equal(color, rgb_set(0, 0.67726, 0)))
		printf("\033[0;32mTRUE\033[0m\n");
	else
	{
		printf("\033[0;31mFALSE\033[0m\n");
		print_color(color, "reflected_color");
	}
}

void	test_mutually_reflective_material(t_world *world)
{
	t_ray			r1;
	t_color			color;
	t_shape			*pl_upper;
	t_shape			*pl_lower;

	pl_upper = ((t_shape *)(world->shapes->content));
	pl_lower = ((t_shape *)(world->shapes->next->content));
	pl_upper->material.reflective = 1;
	pl_lower->material.reflective = 1;
	r1 = ray(point(0, 0, 0), vector(0, 1, 0));
	if (color_at(&color, &r1, world) != 0)
		return ;
	printf("check if mutually reflective material is not segfault\n");
	if (rgb_equal(color, rgb_set(0, 0.67726, 0)))
		printf("\033[0;32mTRUE\033[0m\n");
}

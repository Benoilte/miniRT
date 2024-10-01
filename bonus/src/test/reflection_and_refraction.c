/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_and_refraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:28:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/01 12:15:36 by bebrandt         ###   ########.fr       */
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

void	test_transparency_value(t_world *world, float value)
{
	t_shape	*shape;

	shape = ((t_shape *)(world->shapes->content));
	printf("check if reflective value is equal to %f\n", value);
	if (equalf(shape->material.transparency, value))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
}

void	test_refraction_value(t_world *world, float value)
{
	t_shape	*shape;

	shape = ((t_shape *)(world->shapes->content));
	printf("check if reflective value is equal to %f\n", value);
	if (equalf(shape->material.refractive_index, value))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
}

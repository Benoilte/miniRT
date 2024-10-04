/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_and_refraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:28:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/04 01:16:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_color(t_color c, char *msg);
void	print_n1_and_n2(t_dbl_lst *intersects, t_ray *ray, t_dbl_lst *containers);

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

void	test_refraction_index(t_data *data)
{
	t_ray				r1;
	t_intersect_list	*intersects;
	t_intersect_list	*tmp;
	t_details			details;

	r1 = ray(point(0, 0, -4), vector(0, 0, 1));
	ft_bzero(&details, sizeof(details));
	intersects = NULL;
	if (intersect_world(&intersects, &r1, data->world) != 0)
		return ;
	tmp = intersects;
	while (tmp)
	{
		printf("%p: %.5f - %.5f\n", ((t_intersection *)tmp->content)->shape, ((t_intersection *)tmp->content)->t, ((t_intersection *)tmp->content)->shape->material.refractive_index);
		tmp = tmp->next;
	}
	print_n1_and_n2(intersects, &r1, data->render[0].shape_container);
	dbl_lstclear(&intersects, clear_intersection);
}

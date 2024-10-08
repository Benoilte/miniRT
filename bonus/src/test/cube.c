/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:48:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 14:45:30 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_intersects_cube(t_inter_lst *intersects, float t1, float t2)
{
	float	first_intersect;
	float	second_intersect;

	first_intersect = intersects->intersect.t;
	second_intersect = intersects->next->intersect.t;
	printf("\ncheck if t1 == %.5f and t2 == %.5f\n", t1, t2);
	if (equalf(first_intersect, t1) && equalf(second_intersect, t2))
		printf("\033[0;32mTRUE\033[0m\n");
	else
	{
		printf("\033[0;31mFALSE\033[0m\n");
		printf("t1 == %.5f && t2 == %.5f\n", first_intersect, second_intersect);
	}
}

void	test_inter_cube(t_world *world, \
						t_ray r, \
						float expect_t1, \
						float expect_t2)
{
	t_inter_lst	*intersects;

	intersects = NULL;
	if (intersect_world(&intersects, &r, world) != 0)
		return ;
	check_intersects_cube(intersects, expect_t1, expect_t2);
	inter_lstclear(&intersects);
}

void	test_ray_missing_cube(t_world *world, t_ray r)
{
	t_inter_lst	*intersects;

	intersects = NULL;
	if (intersect_world(&intersects, &r, world) != 0)
		return ;
	printf("\ncheck if ray missing cube\n");
	if (intersects == NULL)
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	inter_lstclear(&intersects);
}

void	test_intersect_cube(t_data *data)
{
	t_shape	*cube;

	cube = add_new_shape_to_world(data->world, CUBE);
	test_inter_cube(data->world, ray(point(5, 0.5, 0), vector(-1, 0, 0)), 4, 6);
	test_inter_cube(data->world, ray(point(-5, 0.5, 0), vector(1, 0, 0)), 4, 6);
	test_inter_cube(data->world, ray(point(0.5, 5, 0), vector(0, -1, 0)), 4, 6);
	test_inter_cube(data->world, ray(point(0.5, -5, 0), vector(0, 1, 0)), 4, 6);
	test_inter_cube(data->world, ray(point(0.5, 0, 5), vector(0, 0, -1)), 4, 6);
	test_inter_cube(data->world, ray(point(0.5, 0, -5), vector(0, 0, 1)), 4, 6);
	test_inter_cube(data->world, ray(point(0, 0.5, 0), vector(0, 0, 1)), -1, 1);
	test_ray_missing_cube(data->world, \
						ray(point(-2, 0, 0), vector(0.2673, 0.5345, 0.8018)));
	test_ray_missing_cube(data->world, \
						ray(point(0, -2, 0), vector(0.8018, 0.2673, 0.5345)));
	test_ray_missing_cube(data->world, \
						ray(point(0, 0, -2), vector(0.5345, 0.8018, 0.2673)));
	test_ray_missing_cube(data->world, ray(point(2, 0, 2), vector(0, 0, -1)));
	test_ray_missing_cube(data->world, ray(point(0, 2, 2), vector(0, -1, 0)));
	test_ray_missing_cube(data->world, ray(point(2, 2, 0), vector(-1, 0, 0)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:00:25 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 13:40:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_compute_normal(t_shape *cube, t_point p, t_vector normal)
{
	t_vector	computed_normal;

	computed_normal = cube->f->normal(cube, &p);
	printf("\ncheck if cube normale is equal to normal(%.5f, %.5f, %.5f)\n", \
												normal.x, normal.y, normal.z);
	if (tp_equal(computed_normal, normal))
		printf("\033[0;32mTRUE\033[0m\n");
	else
	{
		printf("\033[0;31mFALSE\033[0m\n");
		printf("computed normal is equal to normal(%.5f, %.5f, %.5f)\n", \
					computed_normal.x, computed_normal.y, computed_normal.z);
	}
}

void	test_normal_cube(t_data *data)
{
	t_shape	*cube;

	cube = (t_shape *)data->world->shapes->next->content;
	test_compute_normal(cube, point(1, 0.5, -0.8), vector(1, 0, 0));
	test_compute_normal(cube, point(-1, -0.2, 0.9), vector(-1, 0, 0));
	test_compute_normal(cube, point(-0.4, 1, -0.1), vector(0, 1, 0));
	test_compute_normal(cube, point(0.3, -1, -0.7), vector(0, -1, 0));
	test_compute_normal(cube, point(-0.6, 0.3, 1), vector(0, 0, 1));
	test_compute_normal(cube, point(0.4, 0.4, -1), vector(0, 0, -1));
	test_compute_normal(cube, point(1, 1, 1), vector(1, 0, 0));
	test_compute_normal(cube, point(-1, -1, -1), vector(-1, 0, 0));
}

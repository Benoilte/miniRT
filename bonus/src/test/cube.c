/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:48:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 09:45:21 by bebrandt         ###   ########.fr       */
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

void	test_inter_cube(t_world *world, t_ray r, float expect_t1, float expect_t2)
{
	t_inter_lst	*intersects;

	intersects = NULL;
	if (intersect_world(&intersects, &r, world) != 0)
		return ;
	check_intersects_cube(intersects, expect_t1, expect_t2);
	inter_lstclear(&intersects);
}

/*
​ 	​Scenario Outline​: A ray intersects a cube
​ 	  ​Given​ c ← cube()
​ 	    ​And​ r ← ray(<origin>, <direction>)
​ 	  ​When​ xs ← local_intersect(c, r)
​ 	  ​Then​ xs.count = 2
​ 	    ​And​ xs[0].t = <t1>
​ 	    ​And​ xs[1].t = <t2>
​
​ 	  ​Examples​:
​ 	    |        | origin            | direction        | t1 | t2 |
​ 	    | +x     | point(5, 0.5, 0)  | vector(-1, 0, 0) |  4 |  6 |
​ 	    | -x     | point(-5, 0.5, 0) | vector(1, 0, 0)  |  4 |  6 |
​ 	    | +y     | point(0.5, 5, 0)  | vector(0, -1, 0) |  4 |  6 |
​ 	    | -y     | point(0.5, -5, 0) | vector(0, 1, 0)  |  4 |  6 |
​ 	    | +z     | point(0.5, 0, 5)  | vector(0, 0, -1) |  4 |  6 |
​ 	    | -z     | point(0.5, 0, -5) | vector(0, 0, 1)  |  4 |  6 |
​ 	    | inside | point(0, 0.5, 0)  | vector(0, 0, 1)  | -1 |  1 |
*/

void	test_intersect_cube(t_data *data)
{
	add_new_shape_to_world(data->world, CUBE);
	test_inter_cube(data->world, ray(point(5, 0.5, 0), vector(-1, 0, 0)), 4, 6);
	test_inter_cube(data->world, ray(point(-5, 0.5, 0), vector(1, 0, 0)), 4, 6);
	test_inter_cube(data->world, ray(point(0.5, 5, 0), vector(0, -1, 0)), 4, 6);
	test_inter_cube(data->world, ray(point(0.5, -5, 0), vector(0, 1, 0)), 4, 6);
	test_inter_cube(data->world, ray(point(0.5, 0, 5), vector(0, 0, -1)), 4, 6);
	test_inter_cube(data->world, ray(point(0.5, 0, -5), vector(0, 0, 1)), 4, 6);
	test_inter_cube(data->world, ray(point(0, 0.5, 0), vector(0, 0, 1)), -1, 1);
}

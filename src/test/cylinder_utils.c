/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:39:49 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/12 15:37:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_tuple(t_tuple a, char *msg);
void	test_cylinder_normal(t_shape *cl, t_point p, t_vector res);

void	test_intersect_count(t_shape *cl, t_point o, t_vector d, size_t res)
{
	t_ray		r1;
	t_report	report;

	printf("\n\tCount cylinder intersection\n");
	r1 = ray(o, tp_normalize(d));
	cl->f->intersect(&r1, cl, &report);
	printf("\nshould check if count is equal to %ld\n", res);
	if (report.count == res)
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
	{
		printf("\033[0;91mFAILED\033[0;39m\n");
		printf("count = %ld\n", report.count);
		printf("t[0] = %f\n", report.t[0]);
		printf("t[1] = %f\n", report.t[1]);
		print_tuple(ray_position(ray(point(0, 1.5, 0), vector(0.1, 1, 0)), \
													report.t[0]), "pos t[0]");
		print_tuple(ray_position(ray(point(0, 1.5, 0), vector(0.1, 1, 0)), \
													report.t[1]), "pos t[1]");
	}
}

void 	test_ray_hit_cylinder_truncated(t_shape *cylinder)
{
	cylinder->cylinder.min = 1;
	cylinder->cylinder.max = 2;
	cylinder->cylinder.closed = true;
	test_intersect_count(cylinder, point(0, 1.5, 0), vector(0.1, 1, 0), 2);
	test_intersect_count(cylinder, point(0, 3, -5), vector(0, 0, 1), 0);
	test_intersect_count(cylinder, point(0, 0, -5), vector(0, 0, 1), 0);
	test_intersect_count(cylinder, point(0, 2, -5), vector(0, 0, 1), 0);
	test_intersect_count(cylinder, point(0, 1, -5), vector(0, 0, 1), 0);
	test_intersect_count(cylinder, point(0, 1.5, -2), vector(0, 0, 1), 2);
	test_intersect_count(cylinder, point(0, 3, 0), vector(0, -1, 0), 2);
	test_intersect_count(cylinder, point(0, 3, -2), vector(0, -1, 2), 2);
	test_intersect_count(cylinder, point(0, 4, -2), vector(0, -1, 1), 2);
	test_intersect_count(cylinder, point(0, 0, -2), vector(0, 1, 2), 2);
	test_intersect_count(cylinder, point(0, -1, -2), vector(0, 1, 1), 2);
}

/*
​ 	​Scenario Outline​: The normal vector on a cylinder's end caps
​ 	  ​Given​ cyl ← cylinder()
​ 	    ​And​ cyl.minimum ← 1
​ 	    ​And​ cyl.maximum ← 2
​ 	    ​And​ cyl.closed ← true
​ 	  ​When​ n ← local_normal_at(cyl, <point>)
​ 	  ​Then​ n = <normal>
​
​ 	  ​Examples​:
​ 	     | point            | normal           |
​ 	     | point(0, 1, 0)   | vector(0, -1, 0) |
​ 	     | point(0.5, 1, 0) | vector(0, -1, 0) |
​ 	     | point(0, 1, 0.5) | vector(0, -1, 0) |
​ 	     | point(0, 2, 0)   | vector(0, 1, 0)  |
​ 	     | point(0.5, 2, 0) | vector(0, 1, 0)  |
		| point(0, 2, 0.5) | vector(0, 1, 0)  |
*/

int	test_cylinder_utils(t_shape *cylinder)
{
	test_ray_hit_cylinder_truncated(cylinder);
	test_cylinder_normal(cylinder, point(0, 1, 0), vector(0, -1, 0));
	test_cylinder_normal(cylinder, point(0.5, 1, 0), vector(0, -1, 0));
	test_cylinder_normal(cylinder, point(0, 1, 0.5), vector(0, -1, 0));
	test_cylinder_normal(cylinder, point(0, 2, 0), vector(0, 1, 0) );
	test_cylinder_normal(cylinder, point(0.5, 2, 0), vector(0, 1, 0));
	test_cylinder_normal(cylinder, point(0, 2, 0.5), vector(0, 1, 0));
	return (0);
}

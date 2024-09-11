/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:39:49 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 12:44:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	}
}

void 	test_ray_hit_cylinder_truncated(t_shape *cylinder)
{
	cylinder->cylinder.min = 1;
	cylinder->cylinder.max = 2;
	test_intersect_count(cylinder, point(0, 1.5, 0), vector(0.1, 1, 0), 0);
	test_intersect_count(cylinder, point(0, 3, -5), vector(0, 0, 1), 0);
	test_intersect_count(cylinder, point(0, 0, -5), vector(0, 0, 1), 0);
	test_intersect_count(cylinder, point(0, 2, -5), vector(0, 0, 1), 0);
	test_intersect_count(cylinder, point(0, 1, -5), vector(0, 0, 1), 0);
	test_intersect_count(cylinder, point(0, 1.5, -2), vector(0, 0, 1), 2);
}

int	test_cylinder_utils(t_shape *cylinder)
{
	test_ray_hit_cylinder_truncated(cylinder);
	return (0);
}

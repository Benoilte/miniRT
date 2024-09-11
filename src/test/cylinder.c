/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:07:32 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 12:07:07 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_tuple(t_tuple a, char *msg);
int		test_cylinder_utils(t_shape *cylinder);

static void	test_cylinder_creation(t_shape *cylinder)
{
	printf("\nshould check if shape is a cylinder\n");
	if (cylinder->type == CYLINDER)
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if center is at origin\n");
	if (tp_equal(cylinder->center, point(0, 0, 0)))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if min is equal to -1 and max is equal to 1\n");
	if (equalf(cylinder->cylinder.min, -1) && equalf(cylinder->cylinder.max, 1))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if transform matrix is equal to the identity\n");
	if (mx_equal(cylinder->transform, mx_identity()))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if transform matrix is equal to the identity\n");
	if (mx_equal(cylinder->transform, mx_identity()))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
}

void	test_ray_miss_cylinder(t_shape *cylinder, t_point o, t_vector d)
{
	t_ray		r1;
	t_report	report;

	printf("\n\tA ray misses a cylinder\n");
	r1 = ray(o, tp_normalize(d));
	if (cylinder->f->intersect(&r1, cylinder, &report) == false)
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
}

void	test_ray_hit_cylinder(t_shape *cl, t_point o, t_vector d, float t[2])
{
	t_ray		r1;
	t_report	report;

	printf("\n\tA ray strikes a cylinder\n");
	r1 = ray(o, tp_normalize(d));
	if (cl->f->intersect(&r1, cl, &report) == true)
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if t[0] is equal to %f\n", t[0]);
	if (equalf(t[0], report.t[0]))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
	{
		printf("\033[0;91mFAILED\033[0;39m\n");
		printf("t[0] = %f\n", report.t[0]);
	}
	printf("\nshould check if t[1] is equal to %f\n", t[1]);
	if (equalf(t[1], report.t[1]))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
	{
		printf("\033[0;91mFAILED\033[0;39m\n");
		printf("t[1] = %f\n", report.t[1]);
	}
}

void	test_cylinder_normal(t_shape *cl, t_point p, t_vector res)
{
	t_vector	n;

	n = normal_cylinder(cl, &p);
	printf("\n\tGet the cylinder normal\n");
	printf("\nCheck the normal of a cylinder\n");
	if (tp_equal(n, res))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
	{
		printf("\033[0;91mFAILED\033[0;39m\n");
		print_tuple(n, "result is");
		print_tuple(res, "instaed of");
	}
}

int	test_cylinder(void)
{
	t_shape		*cylinder;

	cylinder = create_new_shape(CYLINDER);
	if (!cylinder)
		return (1);
	test_cylinder_creation(cylinder);
	test_ray_miss_cylinder(cylinder, point(1, 0, 0), vector(0, 1, 0));
	test_ray_miss_cylinder(cylinder, point(0, 0, 0), vector(0, 1, 0));
	test_ray_miss_cylinder(cylinder, point(0, 0, -5), vector(1, 1, 1));
	test_ray_hit_cylinder(cylinder, point(1, 0, -5), vector(0, 0, 1), \
							(float [2]){5, 5});
	test_ray_hit_cylinder(cylinder, point(0, 0, -5), vector(0, 0, 1), \
							(float [2]){4, 6});
	test_ray_hit_cylinder(cylinder, point(0.5, 0, -5), vector(0.1, 1, 1), \
							(float [2]){6.808006, 7.088698});
	test_cylinder_normal(cylinder, point(1, 0, 0), vector(1, 0, 0));
	test_cylinder_normal(cylinder, point(0, 5, -1), vector(0, 0, -1));
	test_cylinder_normal(cylinder, point(0, -2, 1), vector(0, 0, 1));
	test_cylinder_normal(cylinder, point(-1, 1, 0), vector(-1, 0, 0));
	test_cylinder_utils(cylinder);
	cylinder->f->destroy(cylinder);
	return (0);
}

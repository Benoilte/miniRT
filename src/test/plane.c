/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:27:18 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/09 17:05:41 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_reset_report(t_report *report);

static void	test_plane_create(t_shape *plane)
{
	printf("\nshould check if shape is a plane\n");
	if (plane->type == PLANE)
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if center is at origin\n");
	if (tp_equal(plane->center, point(0, 0, 0)))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if transform matrix is equal to the identity\n");
	if (mx_equal(plane->transform, mx_identity()))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if transform matrix is equal to the identity\n");
	if (mx_equal(plane->transform, mx_identity()))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
}

static void	test_plane_normal(t_shape *plane)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;

	printf("\n\tThe normal of a plane is constant everywhere\n");
	p1 = point(0, 0, 0);
	p2 = point(10, 0, -10);
	p3 = point(-5, 0, 150);
	printf("\nshould check if normal is equal to vector(0, 1, 0)\n");
	if (tp_equal(plane->f->normal(plane, &p1), vector(0, 1, 0)))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if normal is equal to vector(0, 1, 0)\n");
	if (tp_equal(plane->f->normal(plane, &p2), vector(0, 1, 0)))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if normal is equal to vector(0, 1, 0)\n");
	if (tp_equal(plane->f->normal(plane, &p3), vector(0, 1, 0)))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
}

static void	test_no_intersect(t_shape *plane)
{
	t_ray		r1;
	t_ray		r2;
	t_report	report;

	r1 = ray(point(0, 10, 0), vector(0, 0, 1));
	r2 = ray(point(0, 0, 0), vector(0, 0, 1));
	printf("\n\tIntersect with a ray parallel and coplanar to the plane\n");
	printf("\nshould check if there is no intersection\n");
	if (!plane->f->intersect(&r1, plane, &report))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	printf("\nshould check if there is no intersection\n");
	if (!plane->f->intersect(&r2, plane, &report))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
}

static void	test_intersect(t_shape *plane)
{
	t_ray		r1;
	t_ray		r2;
	t_report	report;

	r1 = ray(point(0, 1, 0), vector(0, -1, 0));
	r2 = ray(point(0, -1, 0), vector(0, 1, 0));
	printf("\n\tA ray intersecting a plane from above and from below\n");
	printf("\nshould check if there is one intersection\n");
	plane->f->intersect(&r1, plane, &report);
	if ((report.count == 1) && (report.t[0] == 1))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	test_reset_report(&report);
	printf("\nshould check if there is one intersection\n");
	plane->f->intersect(&r2, plane, &report);
	if ((report.count == 1) && (report.t[0] == 1))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
}

int	test_plane(void)
{
	t_shape	*plane;

	plane = create_new_shape(PLANE);
	test_plane_create(plane);
	test_plane_normal(plane);
	test_no_intersect(plane);
	test_intersect(plane);
	plane->f->destroy(plane);
	return (0);
}

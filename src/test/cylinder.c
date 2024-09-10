/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:07:32 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/10 13:31:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	test_cylinder_create(t_shape *cylinder)
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

int	test_cylinder(void)
{
	t_shape	*cylinder;

	cylinder = create_new_shape(CYLINDER);
	test_cylinder_create(cylinder);
	// test_cylinder_normal(cylinder);
	// test_no_intersect(cylinder);
	// test_intersect(cylinder);
	cylinder->f->destroy(cylinder);
	return (0);
}

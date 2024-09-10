/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:44:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/10 12:55:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_default_scene(t_data *data);

static	void	test_lighting(	t_vector eyev, \
								bool in_shadow, \
								t_point lightp, \
								t_color result)
{
	t_details	details;
	t_shape		*sp1;
	t_light		light;
	t_color		color;

	sp1 = create_new_shape(SPHERE);
	details.shape = sp1;
	details.eyev = eyev;
	details.normalv = vector(0, 0, -1);
	details.position = point(0, 0, 0);
	details.in_shadow = in_shadow;
	light = set_light(lightp, rgb_set(1, 1, 1));
	color = lighting(&details, &light);
	printf("\nshould check if material color is equal to ");
	printf("color(%f, %f, %f)\n", result.red, result.green, result.blue);
	print_color(color, "resulting color");
	if (rgb_equal(result, color))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	sp1->f->destroy(sp1);
}

static void	test_is_shadowed(t_data *data, t_point point, bool result)
{
	if (result)
		printf("\nshould check if point is in shadow\n");
	else
		printf("\nshould check if point is not in shadow\n");
	if (is_shadowed(data->world, point) == result)
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
}

static void	test_shade_it(t_data *data)
{
	t_shape			*sp;
	t_ray			r1;
	t_intersection	i1;
	t_details		details;
	t_color			color;

	ft_bzero(&details, sizeof(details));
	data->world->light->position = point(0, 0, -10);
	sp = create_new_shape(SPHERE);
	sp->transform = mx_add_translation(sp->transform, 0, 0, 10);
	update_inverse(sp);
	ft_lstadd_back(&data->world->shapes, ft_lstnew(sp));
	r1 = ray(point(0, 0, 5), vector(0, 0, 1));
	i1 = set_intersection(sp, 4);
	compute_details(&details, &i1, r1, data->world);
	color = lighting(&details, data->world->light);
	printf("\ncheck if material color is equal to color(0.1, 0.1, 0.1)\n");
	print_color(color, "resulting color");
	if (rgb_equal(rgb_set(0.1, 0.1, 0.1), color))
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
}

static void	test_hit_offset(t_data *data)
{
	t_shape			*sp;
	t_ray			r1;
	t_intersection	i1;
	t_details		details;

	ft_bzero(&details, sizeof(details));
	r1 = ray(point(0, 0, -5), vector(0, 0, 1));
	sp = create_new_shape(SPHERE);
	sp->transform = mx_add_translation(sp->transform, 0, 0, 1);
	update_inverse(sp);
	i1 = set_intersection(sp, 5);
	compute_details(&details, &i1, r1, data->world);
	printf("\ncheck if over_point.z is smaller tha -EPSILON / 2 and ");
	printf("check if over_point.z is smaller than position.z\n");
	if ((details.over_point.z < (-EPSILON / 2)) \
		&& details.position.z > details.over_point.z)
		printf("\033[0;92mSUCCESS\033[0;39m\n");
	else
		printf("\033[0;91mFAILED\033[0;39m\n");
	sp->f->destroy(sp);
}

int	test_shadow(t_data *data)
{
	test_lighting(vector(0, 0, -1), false, \
					point(0, 0, -10), rgb_set(1.9, 1.9, 1.9));
	test_lighting(vector(0, sqrtf(2) / 2, -sqrtf(2) / 2), false, \
					point(0, 0, -10), rgb_set(1, 1, 1));
	test_lighting(vector(0, 0, -1), false, \
					point(0, 10, -10), rgb_set(0.7364, 0.7364, 0.7364));
	test_lighting(vector(0, -sqrtf(2) / 2, -sqrtf(2) / 2), false, \
					point(0, 10, -10), rgb_set(1.63639, 1.63639, 1.63639));
	test_lighting(vector(0, 0, -1), false, \
					point(0, 0, 10), rgb_set(0.1, 0.1, 0.1));
	test_lighting(vector(0, 0, -1), true, \
					point(0, 0, -10), rgb_set(0.1, 0.1, 0.1));
	set_default_scene(data);
	test_is_shadowed(data, point(0, 10, 0), false);
	test_is_shadowed(data, point(10, -10, 10), true);
	test_is_shadowed(data, point(-20, 20, -20), false);
	test_is_shadowed(data, point(-2, 2, -2), false);
	test_shade_it(data);
	test_hit_offset(data);
	return (0);
}

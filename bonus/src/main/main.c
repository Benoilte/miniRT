/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:20:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/30 16:28:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_reflective_value(t_world *world, float value);

static void	update_shape(t_world *world)
{
	t_shape *shape1;
	t_shape *shape2;

	shape1 = ((t_shape *)(world->shapes->content));
	shape2 = ((t_shape *)(world->shapes->next->content));
	shape1->material.reflective = 0.2;
	shape2->material.reflective = 0.2;
}

int	main(int argc, char **argv)
{
	t_data				*data;

	data = init_data(argc, argv);
	update_shape(data->world);
	test_reflective_value(data->world, 0.5);
	set_hooks(data);
	render(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}

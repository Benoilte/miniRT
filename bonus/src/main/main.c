/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:05:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 12:17:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_transparency_value(t_world *world, float value);
void	test_refraction_value(t_world *world, float value);

int	main(int argc, char **argv)
{
	t_data				*data;

	data = init_data(argc, argv);
	test_transparency_value(data->world, 0);
	test_refraction_value(data->world, 1);
	set_hooks(data);
	timed_render(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}

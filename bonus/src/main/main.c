/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:20:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/30 11:14:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_reflective_value(t_world *world);
void	test_reflective_vector(t_world *world);
void	test_non_rflective_material(t_world *world);

int	main(int argc, char **argv)
{
	t_data				*data;

	data = init_data(argc, argv);
	test_reflective_value(data->world);
	test_reflective_vector(data->world);
	test_non_rflective_material(data->world);
	// set_hooks(data);
	// render(data);
	// mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}

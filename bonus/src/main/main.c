/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:05:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/04 11:22:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_refraction_index(t_data *data);
void	test_details_under_point(t_data *data);

int	main(int argc, char **argv)
{
	t_data				*data;

	data = init_data(argc, argv);
	set_hooks(data);
	test_refraction_index(data);
	test_details_under_point(data);
	timed_render(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}

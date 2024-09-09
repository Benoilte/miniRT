/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:20:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 15:01:45 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_input_data	input;
	t_data			*data;

	printf("Hello, in main program!\n");
	if (init_input(argc, argv, &input) != 0)
		return (1);
	return (0);
	data = init_data();
	set_hooks(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}

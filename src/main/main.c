/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:20:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/16 10:12:03 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data			*data;

	printf("Hello, in main program!\n");
	data = init_data(argc, argv);
	set_hooks(data);
	render(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}

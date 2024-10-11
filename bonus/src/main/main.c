/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:05:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/11 14:57:17 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data				*data;

	data = init_data(argc, argv);
	set_hooks(data);
	timed_render(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}

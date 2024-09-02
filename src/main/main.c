/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:20:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 14:40:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_data	*data;

	printf("Hello, in main default\n");
	data = init_data();
	set_hooks(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}

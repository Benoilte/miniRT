/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:53:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 16:00:29 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit_error(data, "Failed to allocate memory for data");
	data->mlx = init_mlx();
	if (!data->mlx)
		exit_error(data, "Failed to initialize mlx data");
	data->world = init_world();
	if (!data->world)
		exit_error(data, "Failed to initialize world");
	data->camera = init_camera();
	if (!data->camera)
		exit_error(data, "Failed to allocate memory for camera");
	return (data);
}

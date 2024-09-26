/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:53:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 17:04:16 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit_error(data, "Failed to allocate memory for data");
	if (init_input(&data->input, argc, argv) != 0)
		exit_error(data, "Failed to initialize input data");
	data->world = init_world(data->input.token_list);
	if (!data->world)
		exit_error(data, "Failed to initialize world");
	data->camera = init_camera(get_element(data->input.token_list, ID_CAMERA));
	if (!data->camera)
		exit_error(data, "Failed to allocate memory for camera");
	data->mlx = init_mlx();
	if (!data->mlx)
		exit_error(data, "Failed to initialize mlx data");
	return (data);
}

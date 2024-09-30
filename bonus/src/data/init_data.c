/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:53:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/30 17:07:33 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	set_render_info(t_data *data)
{
	const int	slice_size = WIN_HEIGHT / THREAD_COUNT;
	int			i;

	if (WIN_HEIGHT % THREAD_COUNT != 0)
		ft_printf("Warning: WIN_HEIGHT not optimal for multi-thread rendering");
	i = 0;
	while (i < THREAD_COUNT)
	{
		data->render[i].thread_id = i;
		data->render[i].data = data;
		data->render[i].start_line = i * slice_size;
		data->render[i].stop_line = data->render[i].start_line + slice_size;
		data->render[i].reflective_depth = REFLECTIVE_DEPTH;
		i ++;
	}
	return (0);
}

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
	if (set_render_info(data) != 0)
		exit_error(data, "Failed to set render info");
	pthread_mutex_init(&data->print_lock, NULL);
	return (data);
}

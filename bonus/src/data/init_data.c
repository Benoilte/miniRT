/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:53:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/15 22:41:46 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	round_resolution_for_rendering(t_pixel *res)
{
	if (res->x % TILE_WIDTH)
	{
		res->x = (res->x + TILE_WIDTH / 2) / TILE_WIDTH * TILE_WIDTH;
		ft_printf("Resolution width adjusted for rendering purposes\n");
	}
	if (res->y % TILE_HEIGHT)
	{
		res->y = (res->y + TILE_HEIGHT / 2) / TILE_HEIGHT * TILE_HEIGHT;
		ft_printf("Resolution height adjusted for rendering purposes\n");
	}
}

static t_pixel	get_resolution(t_list *token_list)
{
	t_pixel	resolution;
	char	**element;

	element = get_element(token_list, ID_RESOLUTION);
	if (element && count_args((const char **)element) == RESOLUTION_PARAMS + 1)
	{
		resolution.x = ft_atoi(element[1]);
		resolution.y = ft_atoi(element[2]);
	}
	else
	{
		resolution.x = DEFAULT_WIN_WIDTH;
		resolution.y = DEFAULT_WIN_HEIGHT;
	}
	round_resolution_for_rendering(&resolution);
	ft_printf("Resolution set to: %d x %d\n", resolution.x, resolution.y);
	return (resolution);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit_error(data, INIT_DATA_ERR);
	if (init_input(&data->input, argc, argv) != 0)
		exit_error(data, INIT_INPUT_ERR);
	data->resolution = get_resolution(data->input.token_list);
	data->world = init_world(data->input.token_list);
	if (!data->world)
		exit_error(data, INIT_WORLD_ERR);
	data->camera = init_camera(data);
	if (!data->camera)
		exit_error(data, INIT_CAMERA_ERR);
	data->mlx = init_mlx(data->resolution);
	if (!data->mlx)
		exit_error(data, INIT_MLX_ERR);
	if (init_render_settings(data, &data->render) != 0)
		exit_error(data, INIT_RENDER_ERR);
	return (data);
}

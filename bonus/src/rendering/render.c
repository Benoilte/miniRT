/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/16 16:13:42 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	update_progress(t_data *data, int tile_finished)
{
	const int	total_tiles = \
		(data->resolution.x * data->resolution.y) / (TILE_WIDTH * TILE_HEIGHT);
	static int	tile_count = 0;

	if (print_mutex(MTX_LOCK) != 0)
	{
		ft_printf("\r\r\r");
		return ;
	}
	if (tile_finished)
	{
		tile_count++;
		if (tile_count == total_tiles)
			ft_printf("\rRender complete!");
		else
			ft_printf("\r%i %%", (tile_count * 100) / total_tiles);
	}
	else
		tile_count = 0;
	print_mutex(MTX_UNLOCK);
}

int	render_tile(t_render_info *info, t_tile *tile)
{
	t_pixel	pixel;
	t_color	color;
	int		color_int;

	if (!info || !tile)
		return (print_error("render_tile", INVALID_POINTER), -1);
	pixel.y = tile->start.y;
	while (pixel.y <= tile->end.y)
	{
		pixel.x = tile->start.x;
		while (pixel.x <= tile->end.x)
		{
			if (render_pixel(&color, info, &pixel) != 0)
				return (print_error("render_strip", THREAD_ERROR));
			color_int = rgb_stoi(color);
			if (color_int != 0)
				set_pixel_color(info->data, pixel.x, pixel.y, color_int);
			pixel.x++;
		}
		pixel.y++;
	}
	return (0);
}

void	*render_strip(void *arg)
{
	t_render_info	*info;
	t_tile			*tile;

	info = (t_render_info *)arg;
	tile = get_next_tile(&info->data->render.tile_stack);
	while (tile)
	{
		if (render_tile(info, tile) != 0)
			return (destroy_tile(tile), (void *)1);
		destroy_tile(tile);
		update_progress(info->data, 1);
		tile = get_next_tile(&info->data->render.tile_stack);
	}
	return ((void *)0);
}

void	render(t_data *data)
{
	t_thread_info	thread;

	if (!data)
		return ;
	if (init_tile_stack(&data->render.tile_stack, data->resolution) != 0)
		exit_error(data, TILE_ERROR);
	reset_image(data);
	ft_printf("Rendering...\n");
	update_progress(data, 0);
	thread.count = data->render.thread_count;
	thread.created = create_threads(data);
	if (!thread.created)
		exit_error(data, NO_THREAD_ERROR);
	thread.errors = join_threads(data);
	ft_printf("\n");
	handle_any_thread_errors(data, thread);
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
							data->mlx->img, 0, 0);
}

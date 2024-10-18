/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:03:49 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/18 15:11:41 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialize_render(t_data *data, t_thread_info *thread_info)
{
	ft_bzero(thread_info, sizeof(t_thread_info));
	if (init_tile_stack(&data->render.tile_stack, data->resolution) != 0)
		exit_error(data, TILE_ERROR);
	reset_image(data);
	ft_printf("Rendering...\n");
	update_progress(data, 0);
}

void	update_progress(t_data *data, int tile_finished)
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
			ft_printf("\rRender complete!\n");
		else
			ft_printf("\r%i %%", (tile_count * 100) / total_tiles);
	}
	else
		tile_count = 0;
	print_mutex(MTX_UNLOCK);
}

int	display_rendered_image(t_data *data)
{
	if (!data)
		return (print_error("display_rendered_image", INVALID_POINTER));
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
							data->mlx->img, 0, 0);
	return (0);
}

int	redirect_stderr_to_log_file(t_data *data)
{
	const int	flags = O_WRONLY | O_CREAT | O_TRUNC;

	if (data->fd.err_log == -1)
	{
		data->fd.err_log = open(ERR_LOG_FILE, flags, 0644);
		if (data->fd.err_log == -1)
			return (perror(ERR_LOG_FILE), 1);
	}
	if (data->fd.stderr_cpy == -1)
	{
		data->fd.stderr_cpy = dup(STDERR_FILENO);
		if (data->fd.stderr_cpy == -1)
			return (perror("redirect : dup"), 2);
	}
	if (dup2(data->fd.err_log, STDERR_FILENO) == -1)
		return (perror("redirect : dup2"), 3);
	return (0);
}

int	restore_stderr(t_data *data)
{
	if (dup2(data->fd.stderr_cpy, STDERR_FILENO) == -1)
		return (perror("restore : dup2"), 1);
	return (0);
}

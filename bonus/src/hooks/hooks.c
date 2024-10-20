/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:24:45 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/20 14:30:07 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_hooks(t_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx->xvar);
	mlx_hook(data->mlx->win, DESTROYNOTIFY, 0, close_minirt, data);
	mlx_loop_hook(data->mlx->xvar, NULL, NULL);
	mlx_hook(data->mlx->win, KEYPRESS, KEYPRESSMASK, keypress, data);
	mlx_hook(data->mlx->win, BUTTONPRESS, BUTTONPRESSMASK, mouse_down, data);
	mlx_hook(data->mlx->win, BUTTONRELEASE, BUTTONRELEASEMASK, mouse_up, data);
	mlx_hook(data->mlx->win, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_move, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx_macos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:12:56 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 23:56:50 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->img)
		{
			mlx_destroy_image(mlx->xvar, mlx->img);
			mlx->img = NULL;
		}
		if (mlx->win)
		{
			mlx_destroy_window(mlx->xvar, mlx->win);
			mlx->win = NULL;
		}
		if (mlx->xvar)
		{
			mlx_do_key_autorepeaton(mlx->xvar);
			mlx->xvar = NULL;
		}
		free(mlx);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx_macos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:12:56 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 11:05:19 by bebrandt         ###   ########.fr       */
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

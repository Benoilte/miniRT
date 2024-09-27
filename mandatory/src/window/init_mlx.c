/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:33:44 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/23 16:29:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->xvar = mlx_init();
	if (!mlx->xvar)
		return (NULL);
	mlx->win = mlx_new_window(mlx->xvar, WIN_WIDTH, WIN_HEIGHT, WINDOW_NAME);
	if (!mlx->win)
		return (NULL);
	mlx->img = mlx_new_image(mlx->xvar, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img)
		return (NULL);
	mlx->img_data = mlx_get_data_addr(mlx->img, &mlx->bpp, \
									&mlx->line_len, &mlx->endian);
	return (mlx);
}

void	reset_image(t_data *data)
{
	void	*new_img;

	new_img = mlx_new_image(data->mlx->xvar, WIN_WIDTH, WIN_HEIGHT);
	if (!new_img)
	{
		perror("unable to reset image for render");
		return ;
	}
	mlx_destroy_image(data->mlx->xvar, data->mlx->img);
	data->mlx->img = new_img;
	data->mlx->img_data = mlx_get_data_addr(data->mlx->img, \
											&data->mlx->bpp, \
											&data->mlx->line_len, \
											&data->mlx->endian);
}

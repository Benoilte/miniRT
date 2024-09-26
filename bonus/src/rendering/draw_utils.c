/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:07:23 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/23 16:29:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_pixel_color(t_data *data, int x, int y, int color)
{
	char	*p;

	if (x < 0 || x >= WIN_WIDTH || \
		y < 0 || y >= WIN_HEIGHT)
		return ;
	p = data->mlx->img_data + ((y * data->mlx->line_len) + \
								(x * (data->mlx->bpp / 8)));
	*(unsigned int *)p = color;
}

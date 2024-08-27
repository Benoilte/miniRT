/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:26:04 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/27 15:50:33 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_minirt(t_data *data)
{
	printf("Closing miniRT ...\n");
	mlx_loop_end(data->mlx->xvar);
	return (0);
}

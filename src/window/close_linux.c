/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:26:04 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/23 16:29:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_editor(t_data *data)
{
	printf("Closing miniRT_editor...\n");
	mlx_loop_end(data->mlx->xvar);
	return (0);
}

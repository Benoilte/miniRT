/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:05:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 14:53:45 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	destroy_input(&data->input);
	destroy_mlx(data->mlx);
	destroy_world(data->world);
	destroy_camera(data->camera);
	free(data);
}

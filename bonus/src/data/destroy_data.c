/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:05:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 12:28:07 by bgolding         ###   ########.fr       */
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
	destroy_render_settings(&data->render);
	free(data);
}

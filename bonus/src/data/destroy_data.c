/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:05:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/18 12:22:34 by bgolding         ###   ########.fr       */
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
	if (data->stderr_cpy >= 0)
		if (close(data->stderr_cpy) == -1)
			perror("destroy_data : close stderr_cpy");
	if (data->errlog_fd >= 0)
		if (close (data->errlog_fd) == -1)
			perror("destroy_data : close errlog_fd");
	free(data);
}

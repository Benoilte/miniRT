/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:05:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 12:23:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	close_fds(t_err_fds *fd)
{
	if (!fd)
		return ;
	if (fd->stderr_cpy >= 0 && close(fd->stderr_cpy) == -1)
		perror("destroy_data : close stderr_cpy");
	if (fd->err_log >= 0 && close (fd->err_log) == -1)
		perror("destroy_data : close err_log");
}

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	destroy_input(&data->input);
	destroy_mlx(data->mlx);
	destroy_world(data->world);
	destroy_camera(data->camera);
	destroy_render_settings(&data->render);
	close_fds(&data->fd);
	free(data);
}

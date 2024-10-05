/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:56:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/05 14:00:31 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_render_settings(t_render *render)
{
	if (!render)
		return ;
	if (render->blocks)
	{
		free(render->blocks);
		render->blocks = NULL;
	}
	if (render->threads)
	{
		free(render->threads);
		render->threads = NULL;
	}
	pthread_mutex_destroy(&render->print_lock);
}

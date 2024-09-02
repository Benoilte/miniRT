/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:52:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 16:11:55 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_world(t_world *world)
{
	if (!world)
		return ;
	ft_lstclear(&world->shapes, destroy_shape);
	destroy_light(world->light);
	free(world);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:52:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/17 16:32:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_world(t_world *world)
{
	if (!world)
		return ;
	ft_lstclear(&world->shapes, destroy_shape);
	destroy_light(world->light);
	destroy_light(world->ambiant_light);
	free(world);
}

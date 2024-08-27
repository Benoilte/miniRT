/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:52:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/27 14:54:46 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_world(t_world *world)
{
	if (!world)
		return ;
	ft_lstclear(&world->shapes, destroy_shape);
	free(world);
}

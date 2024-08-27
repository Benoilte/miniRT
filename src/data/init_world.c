/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:49:42 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/27 14:55:12 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	*init_world(void)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	if (!world)
		return (NULL);
	return (world);
}

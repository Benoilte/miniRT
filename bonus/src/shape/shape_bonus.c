/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:40:06 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 13:41:03 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_shape_bonus(t_shape *self, char **args)
{
	if (!self || !args)
		return ;
	self->material.diffuse = rt_roundf(ft_atod(args[0]));
	self->material.specular = rt_roundf(ft_atod(args[1]));
	self->material.shininess = rt_roundf(ft_atoi(args[2]));
	self->material.reflective = rt_roundf(ft_atod(args[3]));
	self->material.transparency = rt_roundf(ft_atod(args[4]));
	self->material.refractive_index = rt_roundf(ft_atod(args[5]));
}

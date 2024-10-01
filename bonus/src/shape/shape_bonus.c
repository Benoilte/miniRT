/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:40:06 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 10:41:37 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_shape_bonus(t_shape *self, char **args)
{
	if (!self || !args)
		return ;
	self->material.reflective = rt_roundf(ft_atod(args[0]));
}

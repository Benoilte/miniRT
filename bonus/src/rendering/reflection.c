/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:18:57 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/30 11:13:35 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	reflected_color(t_world *world, t_details *details)
{
	(void)world;
	if (equalf(details->shape->material.reflective, 0))
		return (rgb_set(0, 0, 0));
	else
		return (rgb_set(1, 1, 1));
}

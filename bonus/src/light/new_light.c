/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:52:39 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/27 16:54:14 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	*init_light(char **str)
{
	t_light	*light;

	if (!str)
		return (NULL);
	light = new_light();
	if (!light)
		return (NULL);
	*light = set_light(str_to_tuple(str[1], POINT), \
		rgb_scale(str_to_rgb(str[3]), rt_roundf(ft_atod(str[2]))));
	return (light);
}

t_light	set_light(t_point position, t_color intensity)
{
	return ((t_light){position, intensity});
}

t_light	*new_light(void)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (!new)
	{
		perror("new_light()");
		return (NULL);
	}
	*new = set_light(\
		point(LIGHT_DEFAULT_X, LIGHT_DEFAULT_Y, LIGHT_DEFAULT_Z), \
		rgb_set(LIGHT_DEFAULT_R, LIGHT_DEFAULT_G, LIGHT_DEFAULT_B));
	return (new);
}

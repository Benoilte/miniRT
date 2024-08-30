/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:52:39 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/30 16:43:04 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	set_light(t_point position, t_color intensity)
{
	return ((t_light){position, intensity});
}

t_light	*new_light(t_point position, t_color intensity)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (!new)
	{
		perror("new_light()");
		return (NULL);
	}
	*new = set_light(position, intensity);
	return (new);
}
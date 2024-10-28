/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:35:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/09 15:18:15 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersection	set_intersection(t_shape *shape, float t)
{
	return ((t_intersection){shape, t});
}

t_intersection	*new_intersection(t_shape *shape, float t)
{
	t_intersection	*new;

	new = (t_intersection *)malloc(sizeof(t_intersection));
	if (!new)
	{
		print_error("new_intersection", strerror(errno));
		return (NULL);
	}
	*new = set_intersection(shape, t);
	return (new);
}

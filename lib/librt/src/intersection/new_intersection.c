/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:35:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 23:52:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "intersection.h"

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
		perror("new_intersection allocation memory");
		return (NULL);
	}
	*new = set_intersection(shape, t);
	return (new);
}

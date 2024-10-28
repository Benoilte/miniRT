/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_containers_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:09:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 18:29:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_to_containers(t_shape *to_add, t_dbl_lst **containers)
{
	t_dbl_lst	*tmp;

	tmp = *containers;
	while (tmp)
	{
		if (tmp->content == NULL)
		{
			tmp->content = to_add;
			return ;
		}
		tmp = tmp->next;
	}
}

void	remove_from_containers(t_shape *to_remove, t_dbl_lst **containers)
{
	t_dbl_lst	*tmp;

	tmp = *containers;
	while (tmp && tmp->content)
	{
		if (tmp->content == to_remove)
		{
			tmp->content = NULL;
			if (tmp->next && tmp->next->content)
				dbl_lstmove_back(containers, tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

bool	shape_is_in_containers(t_shape *to_check, t_dbl_lst *containers)
{
	t_dbl_lst	*tmp;

	tmp = containers;
	while (tmp && tmp->content)
	{
		if (tmp->content == to_check)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

float	get_last_refraction_index(t_dbl_lst *containers)
{
	t_dbl_lst	*tmp;

	if (containers->content == NULL)
		return (1);
	tmp = containers;
	while (tmp)
	{
		if ((tmp->next == NULL) || tmp->next->content == NULL)
			return (((t_shape *)tmp->content)->material.refractive_index);
		tmp = tmp->next;
	}
	return (1);
}

void	move_shape(t_shape *shape, t_dbl_lst **containers)
{
	if (shape_is_in_containers(shape, *containers))
		remove_from_containers(shape, containers);
	else
		add_to_containers(shape, containers);
}

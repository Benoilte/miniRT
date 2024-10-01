/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:22:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/01 14:51:58 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_dbl_lst	*get_first_hit(t_dbl_lst **dlist)
{
	return (dbl_lstgetone(dlist, is_hit_positive));
}

void	set_first_hit_valid(t_shape *self, t_intersect_list **first_hit)
{
	t_intersection	*hit;

	if (!*first_hit)
		return ;
	hit = ((t_intersection *)((*first_hit)->content));
	if (hit->shape == self)
		*first_hit = (*first_hit)->next;
}
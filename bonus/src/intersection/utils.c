/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:22:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 18:17:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_inter_lst	*get_first_hit(t_inter_lst **lst)
{
	return (inter_lstgetone(lst, is_hit_positive));
}

void	set_first_hit_valid(t_shape *self, t_inter_lst **first_hit)
{
	if (!*first_hit)
		return ;
	if ((*first_hit)->intersect.shape == self)
		*first_hit = (*first_hit)->next;
}

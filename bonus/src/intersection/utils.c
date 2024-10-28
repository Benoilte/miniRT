/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:22:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/24 07:34:25 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_inter_lst	*get_first_hit(t_inter_lst **lst)
{
	return (inter_lstgetone(lst, is_hit_positive));
}

void	set_first_hit_valid(t_shape *self, t_inter_lst **first_hit, bool inside)
{
	if (!*first_hit)
		return ;
	if (((*first_hit)->intersect.shape == self) && !inside)
		*first_hit = (*first_hit)->next;
}

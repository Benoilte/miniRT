/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstadd_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:14:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:15:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

void	inter_lstadd_after(t_inter_lst **lst, t_inter_lst *new, t_inter_lst *el)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (el->next)
		el->next->prev = new;
	new->next = el->next;
	el->next = new;
	new->prev = el;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstadd_before.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:17:05 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:38:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

void	inter_lstadd_before(t_inter_lst **lst, \
							t_inter_lst *new, \
							t_inter_lst *el)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!el->prev)
	{
		inter_lstadd_front(lst, new);
		return ;
	}
	el->prev->next = new;
	new->prev = el->prev;
	el->prev = new;
	new->next = el;
}

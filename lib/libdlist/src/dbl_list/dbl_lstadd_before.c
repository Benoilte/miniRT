/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_eladd_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:03:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 16:53:38 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dbl_lstadd_before(t_dbl_lst **dlst, t_dbl_lst *new, t_dbl_lst *el)
{
	if (!*dlst)
	{
		*dlst = new;
		return ;
	}
	if (!el->prev)
	{
		dbl_lstadd_front(dlst, new);
		return ;
	}
	el->prev->next = new;
	new->prev = el->prev;
	el->prev = new;
	new->next = el;
}

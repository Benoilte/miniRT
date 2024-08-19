/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstadd_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:24:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 17:28:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

void	dbl_lstadd_after(t_dbl_lst **lst, t_dbl_lst *new, t_dbl_lst *el)
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

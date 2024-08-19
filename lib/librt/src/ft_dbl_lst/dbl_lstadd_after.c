/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstadd_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:24:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 19:32:49 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

void	dbl_lstadd_after(t_dbl_lst **dlst, t_dbl_lst *new, t_dbl_lst *el)
{
	if (!*dlst)
	{
		*dlst = new;
		return ;
	}
	if (el->next)
		el->next->prev = new;
	new->next = el->next;
	el->next = new;
	new->prev = el;
}

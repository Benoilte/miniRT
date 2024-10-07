/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:14:19 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:16:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

void	inter_lstadd_back(t_inter_lst **lst, t_inter_lst *new)
{
	t_inter_lst	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = inter_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstmove_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:34:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:35:07 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

void	inter_lstmove_back(t_inter_lst **lst, t_inter_lst *to_move)
{
	t_inter_lst	*last;

	last = inter_lstlast(*lst);
	if (to_move->prev == NULL)
	{
		*lst = to_move->next;
		if (to_move->next)
			to_move->next->prev = NULL;
	}
	else
	{
		to_move->prev->next = to_move->next;
		if (to_move->next)
			to_move->next->prev = to_move->prev;
	}
	to_move->next = NULL;
	to_move->prev = last;
	last->next = to_move;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstmove_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:42:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/04 08:46:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dbl_lstmove_back(t_dbl_lst **dlst, t_dbl_lst *to_move)
{
	t_dbl_lst	*last;

	last = dbl_lstlast(*dlst);
	if (to_move->prev == NULL)
	{
		*dlst = to_move->next;
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

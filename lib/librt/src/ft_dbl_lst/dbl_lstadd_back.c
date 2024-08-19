/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:04:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 19:33:07 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

void	dbl_lstadd_back(t_dbl_lst **dlst, t_dbl_lst *new)
{
	t_dbl_lst	*last;

	if (!dlst || !new)
		return ;
	if (!*dlst)
		*dlst = new;
	else
	{
		last = dbl_lstlast(*dlst);
		last->next = new;
		new->prev = last;
	}
}

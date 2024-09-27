/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstadd_ordered.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:05:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/19 14:13:57 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dbl_lstadd_ordered(t_dbl_lst **dlst, \
							t_dbl_lst *new, \
							bool (*f)(t_dbl_lst *, t_dbl_lst *))
{
	t_dbl_lst	*tmp;
	t_dbl_lst	*prev;

	if (!dlst || !new || !f)
		return ;
	tmp = *dlst;
	prev = tmp;
	while (tmp)
	{
		if (f(new, tmp))
		{
			dbl_lstadd_before(dlst, new, tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	dbl_lstadd_after(dlst, new, prev);
}

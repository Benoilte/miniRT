/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstadd_ordered.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:19:11 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:20:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

void	inter_lstadd_ordered(t_inter_lst **lst, \
							t_inter_lst *new, \
							bool (*f)(t_inter_lst *, t_inter_lst *))
{
	t_inter_lst	*tmp;
	t_inter_lst	*prev;

	if (!lst || !new || !f)
		return ;
	tmp = *lst;
	prev = tmp;
	while (tmp)
	{
		if (f(new, tmp))
		{
			inter_lstadd_before(lst, new, tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	inter_lstadd_after(lst, new, prev);
}

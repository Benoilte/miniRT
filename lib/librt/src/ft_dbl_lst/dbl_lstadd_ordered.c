/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstadd_ordered.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:05:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 17:29:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

/*if function f return 1 add new element */
void	dbl_lstadd_ordered(t_dbl_lst **lst, t_dbl_lst *new, int (*f)(t_dbl_lst *, t_dbl_lst *))
{
	t_dbl_lst	*tmp;
	t_dbl_lst	*prev;
	
	if (!lst || !new || !f)
		return ;
	tmp = *lst;
	while (tmp)
	{
		if (f(new, tmp))
		{
			dbl_lstadd_before(lst, new, tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	dbl_lstadd_after(lst, new, prev);
}

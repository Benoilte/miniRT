/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:26:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:32:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

void	inter_lstiter(t_inter_lst *lst, void (*f)(t_intersection *))
{
	t_inter_lst	*tmp;

	if (!f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(&tmp->intersect);
		tmp = tmp->next;
	}
}

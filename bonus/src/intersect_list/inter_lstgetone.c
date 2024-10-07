/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstgetone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:25:38 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:26:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

t_inter_lst	*inter_lstgetone(t_inter_lst **lst, bool (*f)(t_inter_lst *))
{
	t_inter_lst	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = *lst;
	while (tmp)
	{
		if (f(tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:20:37 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:24:49 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

void	inter_lstclear(t_inter_lst **lst)
{
	t_inter_lst	*to_del;
	t_inter_lst	*next;

	to_del = *lst;
	*lst = NULL;
	while (to_del != NULL)
	{
		next = to_del->next;
		free(to_del);
		to_del = next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:18:22 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:18:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

void	inter_lstadd_front(t_inter_lst **lst, t_inter_lst *new)
{
	if (!lst || !new)
		return ;
	if ((*lst))
		(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}

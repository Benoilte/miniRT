/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:05:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 16:29:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

void	dbl_lstadd_front(t_dbl_lst **lst, t_dbl_lst *new)
{
	if (!lst || !new)
		return ;
	if ((*lst))
		(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}
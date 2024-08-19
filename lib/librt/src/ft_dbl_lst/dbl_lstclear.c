/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:04:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 13:31:09 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

void	dbl_lstclear(t_dbl_lst **lst, void (*del)(void *))
{
	t_dbl_lst	*to_del;
	t_dbl_lst	*next;

	to_del = *lst;
	*lst = NULL;
	while (to_del != NULL)
	{
		next = to_del->next;
		dbl_lstdelone(to_del, del);
		to_del = next;
	}
}
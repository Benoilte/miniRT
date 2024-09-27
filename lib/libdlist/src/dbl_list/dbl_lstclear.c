/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:04:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/22 09:31:51 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dbl_lstclear(t_dbl_lst **dlst, void (*del)(void *))
{
	t_dbl_lst	*to_del;
	t_dbl_lst	*next;

	to_del = *dlst;
	*dlst = NULL;
	while (to_del != NULL)
	{
		next = to_del->next;
		dbl_lstdelone(to_del, del);
		to_del = next;
	}
}

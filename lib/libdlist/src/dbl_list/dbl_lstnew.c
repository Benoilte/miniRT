/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:39:00 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/22 09:32:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dbl_lst	*dbl_lstnew(void *content)
{
	t_dbl_lst	*new;

	new = (t_dbl_lst *)malloc(sizeof(t_dbl_lst));
	if (!new)
	{
		perror("dbl_lst_new allocation memory");
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

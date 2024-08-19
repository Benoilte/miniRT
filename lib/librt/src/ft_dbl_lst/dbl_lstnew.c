/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:39:00 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 13:05:11 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

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

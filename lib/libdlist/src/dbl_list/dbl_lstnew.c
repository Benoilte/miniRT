/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:39:00 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/09 15:13:37 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dbl_lst	*dbl_lstnew(void *content)
{
	t_dbl_lst	*new;

	new = (t_dbl_lst *)malloc(sizeof(t_dbl_lst));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

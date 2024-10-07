/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:35:36 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 17:36:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_list.h"

t_inter_lst	*inter_lstnew(t_shape *shape, float t)
{
	t_inter_lst	*new;

	new = (t_inter_lst *)malloc(sizeof(t_inter_lst));
	if (!new)
	{
		perror("dbl_lst_new allocation memory");
		return (NULL);
	}
	new->intersect.shape = shape;
	new->intersect.t = t;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:28:57 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/16 13:44:29 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Removes and returns the top node from the given list.
	Updates the list head to point at the next node.
	Returns NULL if the list is empty or invalid.
*/

t_list	*ft_lstpop_top(t_list **list)
{
	t_list	*popped_node;

	if (!list || !(*list))
		return (NULL);
	popped_node = *list;
	*list = (*list)->next;
	popped_node->next = NULL;
	return (popped_node);
}

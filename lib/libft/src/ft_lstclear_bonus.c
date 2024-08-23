/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:18:48 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:14:25 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Deletes and frees the given node and every successor of that node,
	using the function 'del' and free(3). Finally, the pointer to the
	list must be set to NULL.
*/

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

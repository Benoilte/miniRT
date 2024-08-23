/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:32:13 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:14:52 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Iterates on the list 'lst' and applies the function 'f'
	on the content of each node.
*/

#include "../inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

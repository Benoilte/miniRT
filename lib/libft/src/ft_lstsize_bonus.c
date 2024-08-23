/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:38:09 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:16:14 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Counts the number of nodes in a list.
*/

#include "../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	if (!lst)
		return (0);
	n = 1;
	while (lst->next)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

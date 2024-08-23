/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:37:36 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:14:44 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Takes as a parameter a node and frees the memory of the node's content 
	using the function 'del' given as a parameter and frees the node.
	The memory of 'next' must not be freed.
*/

#include "../inc/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

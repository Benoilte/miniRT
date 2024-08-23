/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:27:38 by bgolding          #+#    #+#             */
/*   Updated: 2023/12/08 13:14:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Adds the node 'new' at the beginning of the list.
*/

#include "../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

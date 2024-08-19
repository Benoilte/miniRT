/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:06:16 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 13:17:17 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

t_dbl_lst	*dbl_lstlast(t_dbl_lst *lst)
{
	t_dbl_lst	*tmp;

	if (!lst)
		return ((void *)0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:06:16 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/22 09:32:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dbl_lst	*dbl_lstlast(t_dbl_lst *dlst)
{
	t_dbl_lst	*tmp;

	if (!dlst)
		return ((void *)0);
	tmp = dlst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

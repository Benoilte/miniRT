/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:58:33 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/22 09:32:02 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dbl_lstiter(t_dbl_lst *dlst, void (*f)(void *))
{
	t_dbl_lst	*tmp;

	if (!f)
		return ;
	tmp = dlst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

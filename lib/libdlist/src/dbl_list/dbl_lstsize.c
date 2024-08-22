/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:06:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/22 09:32:17 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int	dbl_lstsize(t_dbl_lst *dlst)
{
	int			i;
	t_dbl_lst	*tmp;

	i = 0;
	tmp = dlst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

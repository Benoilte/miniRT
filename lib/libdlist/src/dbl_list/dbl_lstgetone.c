/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstgetone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:56:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/22 09:31:58 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dbl_lst	*dbl_lstgetone(t_dbl_lst **dlst, bool (*f)(t_dbl_lst *))
{
	t_dbl_lst	*tmp;

	if (!dlst || !f)
		return (NULL);
	tmp = *dlst;
	while (tmp)
	{
		if (f(tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

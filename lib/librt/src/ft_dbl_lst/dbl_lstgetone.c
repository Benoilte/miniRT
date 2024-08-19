/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstgetone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:56:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 18:02:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

t_dbl_lst	*dbl_lstgetone(t_dbl_lst **lst, int (*f)(t_dbl_lst *))
{
	t_dbl_lst	*tmp;
	
	if (!lst || !f)
		return (NULL);
	tmp = *lst;
	while (tmp)
	{
		if (f(tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
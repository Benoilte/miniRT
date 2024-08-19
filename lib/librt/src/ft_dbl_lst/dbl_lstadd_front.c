/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:05:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 19:33:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_lst.h"

void	dbl_lstadd_front(t_dbl_lst **dlst, t_dbl_lst *new)
{
	if (!dlst || !new)
		return ;
	if ((*dlst))
		(*dlst)->prev = new;
	new->next = *dlst;
	*dlst = new;
}

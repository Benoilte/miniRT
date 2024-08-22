/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:06:05 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/22 09:31:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dbl_lstdelone(t_dbl_lst *dlst, void (*del)(void *))
{
	if (!dlst)
		return ;
	del(dlst->content);
	free(dlst);
}

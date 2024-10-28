/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_shape_containers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:58:36 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/03 23:59:43 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	reset_shape_container(t_dbl_lst *containers)
{
	t_dbl_lst	*tmp;

	tmp = containers;
	while (tmp)
	{
		tmp->content = NULL;
		tmp = tmp->next;
	}
}

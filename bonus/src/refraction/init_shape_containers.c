/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shape_containers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:39:30 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/04 00:41:33 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_container(t_dbl_lst *containers);

int	init_shape_container(size_t size, t_dbl_lst **containers)
{
	t_dbl_lst	*new;

	*containers = NULL;
	while (size > 0)
	{
		new = dbl_lstnew(NULL);
		if (!new)
			return (1);
		dbl_lstadd_back(containers, new);
		size--;
	}
	return (0);
}

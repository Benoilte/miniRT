/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:48:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 18:12:58 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

bool	is_hit_positive(t_inter_lst *lst)
{
	return (lst->intersect.t >= 0);
}

bool	add_new_before_lst(t_inter_lst *new, t_inter_lst *lst)
{
	float	new_i;
	float	cur_i;
	float	prev_i;

	new_i = new->intersect.t;
	cur_i = lst->intersect.t;
	prev_i = 0;
	if (lst->prev)
		prev_i = lst->prev->intersect.t;
	return (((new_i < cur_i) || equalf(new_i, cur_i))
		&& ((lst->prev == NULL) || new_i > prev_i));
}

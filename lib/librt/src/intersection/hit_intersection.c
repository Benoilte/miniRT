/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:48:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 19:49:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "intersection.h"

bool	is_hit_positive(t_dbl_lst *intersection)
{
	return (((t_intersection *)intersection->content)->t >= 0);
}

bool	add_new_before_lst(t_dbl_lst *new, t_dbl_lst *lst)
{
	float	new_i;
	float	cur_i;
	float	prev_i;

	new_i = ((t_intersection *)new->content)->t;
	cur_i = ((t_intersection *)lst->content)->t;
	if ((t_intersection *)lst->prev)
		prev_i = ((t_intersection *)lst->prev->content)->t;
	return (((new_i < cur_i) || equalf(new_i, cur_i)) && ((lst->prev == NULL) || new_i > prev_i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:54:16 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 17:40:44 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "intersection.h"

int	add_intersection(t_dbl_lst *new, t_dbl_lst *lst)
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

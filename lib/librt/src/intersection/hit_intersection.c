/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:48:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 17:54:56 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "intersection.h"

int	get_positive_hit(t_dbl_lst *intersection)
{
	return (((t_intersection *)intersection->content)->t >= 0);
}
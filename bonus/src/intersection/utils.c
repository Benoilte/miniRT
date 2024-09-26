/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:22:26 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/04 12:24:59 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_dbl_lst	*get_first_hit(t_dbl_lst **dlist)
{
	return (dbl_lstgetone(dlist, is_hit_positive));
}

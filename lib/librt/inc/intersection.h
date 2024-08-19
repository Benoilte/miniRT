/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:01:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 17:59:00 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

//	INCLUDES

#include <stdlib.h>
#include <stdio.h>
#include "ft_dbl_lst.h"
#include "math_utils.h"

//	TYPEDEFS

typedef struct s_intersection
{
	void	*shape;
	float	t;
}	t_intersection;

// PROTOTYPES

t_intersection	set_intersection(void *shape, float t);
t_intersection	*new_intersection(void *shape, float t);
int				add_intersection(t_dbl_lst *new, t_dbl_lst *current);
int				get_positive_hit(t_dbl_lst *intersection);
void			clear_intersection(void *intersection);

#endif
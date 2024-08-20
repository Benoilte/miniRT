/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:01:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/20 11:11:09 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

//	INCLUDES

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "shape.h"
# include "ft_dbl_lst.h"
# include "math_utils.h"

//	TYPEDEFS

typedef struct s_intersection
{
	t_shape	*shape;
	float	t;
}	t_intersection;

// PROTOTYPES

t_intersection	set_intersection(t_shape *shape, float t);
t_intersection	*new_intersection(t_shape *shape, float t);
bool			add_new_before_lst(t_dbl_lst *new, t_dbl_lst *lst);
bool			is_hit_positive(t_dbl_lst *intersection);
void			clear_intersection(void *intersection);

#endif

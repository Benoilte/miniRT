/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:01:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/21 11:23:31 by bgolding         ###   ########.fr       */
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

//	DEFINES

# define REPORT_BUFFER_SIZE (2)

//	TYPEDEFS

typedef t_dbl_lst	t_intersect_list;
typedef struct s_shape t_shape;

typedef struct s_intersection
{
	t_shape	*shape;
	float	t;
}	t_intersection;

typedef struct s_intersect_report
{
	size_t	count;
	float	t[REPORT_BUFFER_SIZE];
}			t_intersect_report;

// PROTOTYPES

t_intersection	set_intersection(t_shape *shape, float t);
t_intersection	*new_intersection(t_shape *shape, float t);
bool			add_new_before_lst(t_dbl_lst *new, t_dbl_lst *lst);
bool			is_hit_positive(t_dbl_lst *intersection);
void			clear_intersection(void *intersection);

#endif

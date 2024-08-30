/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:01:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/30 11:54:44 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

//	INCLUDES

# include "minirt.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

//	DEFINES

# define REPORT_BUFFER_SIZE (2)

//	TYPEDEFS

typedef t_dbl_lst		t_intersect_list;
typedef struct s_shape	t_shape;

typedef struct s_intersection
{
	t_shape	*shape;
	float	t;
}	t_intersection;

typedef struct s_intersection_details
{
	t_shape	*shape;
	float	t;
	t_point		position;
	t_vector	normalv;
	t_vector	eyev;
	bool		inside;
}	t_intersection_details;

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
t_intersection_details	set_details_intersection(t_intersection *hit, t_ray ray);

#endif

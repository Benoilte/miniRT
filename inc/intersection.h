/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:01:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/04 12:25:18 by bgolding         ###   ########.fr       */
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

# define REPORT_BUFFER_SIZE 2

//	TYPEDEFS - forward declarations

typedef struct s_ray	t_ray;

//	TYPEDEFS

typedef t_dbl_lst		t_intersect_list;
typedef struct s_shape	t_shape;

typedef struct s_intersection
{
	t_shape	*shape;
	float	t;
}	t_intersection;

typedef struct s_intersect_details
{
	t_shape		*shape;
	float		t;
	t_point		position;
	t_vector	normalv;
	t_vector	eyev;
	bool		inside;
}	t_intersect_details;

typedef struct s_intersect_report
{
	size_t	count;
	float	t[REPORT_BUFFER_SIZE];
}			t_intersect_report;

// PROTOTYPES

t_intersection		set_intersection(t_shape *shape, float t);
t_intersection		*new_intersection(t_shape *shape, float t);
bool				add_new_before_lst(t_dbl_lst *new, t_dbl_lst *lst);
bool				is_hit_positive(t_dbl_lst *intersection);
void				clear_intersection(void *intersection);
t_intersect_details	set_intersect_details(t_intersection *hit, t_ray ray);
t_dbl_lst			*get_first_hit(t_dbl_lst **dlist);

#endif

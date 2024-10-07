/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:01:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 18:46:09 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

//	INCLUDES

# include "minirt.h"
# include "intersect_list.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

//	DEFINES

# define REPORT_BUFFER_SIZE 2

# define INTERSECT_INCOMPLETE "unable to compute intersections"

//	TYPEDEFS

typedef struct s_intersect_details
{
	t_shape		*shape;
	float		t;
	t_point		position;
	t_vector	normalv;
	t_vector	eyev;
	t_vector	reflectv;
	bool		inside;
	int			in_shadow;
	t_point		over_point;
	t_point		under_point;
	float		n1;
	float		n2;
}	t_intersect_details;

typedef struct s_intersect_report
{
	size_t	count;
	float	t[REPORT_BUFFER_SIZE];
}			t_intersect_report;

// PROTOTYPES

t_intersection	set_intersection(t_shape *shape, float t);
t_intersection	*new_intersection(t_shape *shape, float t);
bool			add_new_before_lst(t_inter_lst *new, t_inter_lst *lst);
bool			is_hit_positive(t_inter_lst *intersection);
void			clear_intersection(void *intersection);
int				compute_details(t_details *details, t_intersection *hit, \
								t_ray ray);
t_inter_lst		*get_first_hit(t_inter_lst **lst);
void			set_first_hit_valid(t_shape *self, t_inter_lst **first_hit);
void			set_over_point(t_details *details);
void			set_under_point(t_details *details);

#endif

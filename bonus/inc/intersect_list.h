/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:49:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/09 15:17:04 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_LIST_H
# define INTERSECT_LIST_H

//	INCLUDES

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# include "forward_declarations.h"
# include "error_handling.h"

//	TYPEDEFS

typedef struct s_intersection
{
	t_shape	*shape;
	float	t;
}	t_intersection;

typedef struct s_intersect_list
{
	struct s_intersection	intersect;
	struct s_intersect_list	*next;
	struct s_intersect_list	*prev;
}	t_intersect_list;

//	PROTOTYPES

typedef t_intersect_list		t_inter_lst;

t_inter_lst	*inter_lstnew(t_shape *shape, float t);
t_inter_lst	*inter_lstgetone(t_inter_lst **lst, bool (*f)(t_inter_lst *));
t_inter_lst	*inter_lstlast(t_inter_lst *lst);
void		inter_lstiter(t_inter_lst *lst, void (*f)(t_intersection *));
void		inter_lstclear(t_inter_lst **lst);
void		inter_lstdelone(t_inter_lst *lst);
void		inter_lstadd_back(t_inter_lst **lst, t_inter_lst *new);
void		inter_lstadd_front(t_inter_lst **lst, t_inter_lst *new);
void		inter_lstadd_ordered(t_inter_lst **lst, t_inter_lst *new, \
									bool (*f)(t_inter_lst *, t_inter_lst *));
void		inter_lstadd_before(t_inter_lst **lst, t_inter_lst *new, \
															t_inter_lst *el);
void		inter_lstadd_after(t_inter_lst **lst, t_inter_lst *new, \
															t_inter_lst *el);
int			inter_lstsize(t_inter_lst *lst);
void		inter_lstmove_back(t_inter_lst **lst, t_inter_lst *to_move);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:52:33 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 19:45:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DBL_LST_H
# define FT_DBL_LST_H

//	INCLUDES

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//	TYPEDEFS

typedef struct	s_dbl_lst
{
	void				*content;
	struct s_dbl_lst	*next;
	struct s_dbl_lst	*prev;
}	t_dbl_lst;


//	PROTOTYPES

t_dbl_lst	*dbl_lstnew(void *content);
t_dbl_lst	*dbl_lstgetone(t_dbl_lst **dlst, bool (*f)(t_dbl_lst *));
t_dbl_lst	*dbl_lstlast(t_dbl_lst *dlst);
void		dbl_lstiter(t_dbl_lst *dlst, void (*f)(void *));
void		dbl_lstclear(t_dbl_lst **dlst, void (*del)(void *));
void		dbl_lstdelone(t_dbl_lst *dlst, void (*del)(void *));
void		dbl_lstadd_back(t_dbl_lst **dlst, t_dbl_lst *new);
void		dbl_lstadd_front(t_dbl_lst **dlst, t_dbl_lst *new);
void		dbl_lstadd_ordered(t_dbl_lst **dlst, t_dbl_lst *new, bool (*f)(t_dbl_lst *, t_dbl_lst *));
void		dbl_lstadd_before(t_dbl_lst **dlst, t_dbl_lst *new, t_dbl_lst *el);
void		dbl_lstadd_after(t_dbl_lst **dlst, t_dbl_lst *new, t_dbl_lst *el);
int			dbl_lstsize(t_dbl_lst *dlst);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:49:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/02 12:49:25 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

void	print_inter(void *inter)
{
	t_intersection	*i1;

	i1 = ((t_intersection *)inter);
	printf("t = %f\n", i1->t);
}

void	print_dbl_lst(t_dbl_lst *dbl_lst)
{
	t_dbl_lst *tmp;

	tmp = dbl_lst;
	while (tmp)
	{
		if (tmp->prev && tmp->next)
			printf("prev = %15f - curr = %15f - next = %15f\n",((t_intersection *)tmp->prev->content)->t, ((t_intersection *)tmp->content)->t, ((t_intersection *)tmp->next->content)->t);
		else if (tmp->prev)
			printf("prev = %15f - curr = %15f - next = %15p\n",((t_intersection *)tmp->prev->content)->t, ((t_intersection *)tmp->content)->t, tmp->next);
		else 
			printf("prev = %15p - curr = %15f - next = %15f\n",tmp->prev, ((t_intersection *)tmp->content)->t, ((t_intersection *)tmp->next->content)->t);
		tmp = tmp->next;
	}
}

int	main(void)
{
	t_dbl_lst		*root;
	t_dbl_lst		*buff;
	t_intersection	*i1;
	t_intersection	*i2;
	t_intersection	*i3;
	t_intersection	*i4;
	t_intersection	*i5;
	t_intersection	*i6;
	t_intersection	*i7;
	t_intersection	*i8;

	root = NULL;
	i1 = new_intersection(NULL, 42);
	i2 = new_intersection(NULL, 43);
	i3 = new_intersection(NULL, 3);
	i4 = new_intersection(NULL, 38);
	i5 = new_intersection(NULL, 101);
	i6 = new_intersection(NULL, -12);
	i7 = new_intersection(NULL, -56);
	i8 = new_intersection(NULL, -42);
	buff = dbl_lstnew(i3);
	dbl_lstadd_ordered(&root, dbl_lstnew(i1), &add_new_before_lst);
	dbl_lstadd_ordered(&root, dbl_lstnew(i2), &add_new_before_lst);
	dbl_lstadd_ordered(&root, buff, &add_new_before_lst);
	dbl_lstadd_ordered(&root, dbl_lstnew(i4), &add_new_before_lst);
	dbl_lstadd_ordered(&root, dbl_lstnew(i5), &add_new_before_lst);
	dbl_lstadd_ordered(&root, dbl_lstnew(i6), &add_new_before_lst);
	dbl_lstadd_ordered(&root, dbl_lstnew(i7), &add_new_before_lst);
	dbl_lstadd_ordered(&root, dbl_lstnew(i8), &add_new_before_lst);
	print_dbl_lst(root);
	printf("dbl_lst size = %d\n", dbl_lstsize(root));
	printf("first positive hit = %f\n", ((t_intersection *)(dbl_lstgetone(&root, &is_hit_positive)->content))->t);
	// printf("first positive hit = %p\n", ((t_intersection *)(dbl_lstgetone(&root, &get_positive_hit))));
	dbl_lstclear(&root, &clear_intersection);
}
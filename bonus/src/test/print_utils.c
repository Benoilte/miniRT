/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:05:55 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/07 18:42:30 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_n1_and_n2(t_inter_lst *intersects, \
						t_ray *ray, \
						t_dbl_lst *containers)
{
	t_inter_lst	*tmp;
	t_details	details;
	int			i;

	i = 0;
	tmp = intersects;
	printf("| i |\t|   n1    |\t|   n2    |\n");
	while (tmp)
	{
		compute_details(&details, &tmp->intersect, *ray);
		compute_refraction_indices(intersects, &details, containers);
		printf("| %d |\t| %.5f |\t| %.5f |\n", i, details.n1, details.n2);
		tmp = tmp->next;
		i++;
	}
}

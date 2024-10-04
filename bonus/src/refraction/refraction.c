/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:17:18 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/04 01:18:00 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
If the intersection is the hit, set n1 to the refractive index of the last
object in the containers list. If that list is empty,
then there is no containing object, and n1 should be set to 1.

If the intersection’s object is already in the containers list,
then this intersection must be exiting the object.
Remove the object from the containers list in this case.
Otherwise, the intersection is entering the object,
and the object should be added to the end of the list.

If the intersection is the hit, set n2 to the refractive index
of the last object in the containers list. If that list is empty, then again,
there is no containing object and n2 should be set to 1.

If the intersection is the hit, terminate the loop here.
*/

void	print_container(t_dbl_lst *containers);

void	compute_refraction_indices(	t_dbl_lst *intersects, \
									t_details *details, \
									t_dbl_lst *containers)
{
	t_dbl_lst	*tmp;

	tmp = intersects;
	reset_shape_container(containers);
	while (tmp)
	{
		if (equalf(((t_intersection *)tmp->content)->t, details->t))
		{
			details->n1 = get_last_refraction_index(containers);
			move_shape(((t_intersection *)tmp->content)->shape, &containers);
			details->n2 = get_last_refraction_index(containers);
			break ;
		}
		else
			move_shape(((t_intersection *)tmp->content)->shape, &containers);
		tmp = tmp->next;
	}
}

void	print_n1_and_n2(t_dbl_lst *intersects, t_ray *ray, t_dbl_lst *containers)
{
	t_dbl_lst	*tmp;
	t_details	details;
	int			i;

	i = 0;
	tmp = intersects;
	printf("| i |\t|   n1    |\t|   n2    |\n");
	while (tmp)
	{
		compute_details(&details, ((t_intersection *)tmp->content), *ray);
		compute_refraction_indices(intersects, &details, containers);
		printf("| %d |\t| %.5f |\t| %.5f |\n", i, details.n1, details.n2);
		tmp = tmp->next;
		i++;
	}
}

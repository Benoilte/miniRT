/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:15:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/04 09:07:39 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFRACTION_H
# define REFRACTION_H

//	INCLUDES

# include "minirt.h"

//	TYPEDEFS


//	PROTOTYPES

void	compute_refraction_indices(t_dbl_lst *intersects, \
									t_details *details, t_dbl_lst *containers);

int		init_shape_container(size_t size, t_dbl_lst **containers);
void	destroy_shape_container(t_dbl_lst **containers);
void	reset_shape_container(t_dbl_lst *containers);

void	add_to_containers(t_shape *to_add, t_dbl_lst **containers);
void	remove_from_containers(t_shape *to_remove, t_dbl_lst **containers);
bool	shape_is_in_containers(t_shape *to_check, t_dbl_lst *containers);
float	get_last_refraction_index(t_dbl_lst *containers);
void	move_shape(t_shape *shape, t_dbl_lst **containers);

#endif

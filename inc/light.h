/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/30 14:46:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

//	INCLUDES

# include "minirt.h"

// DEFINES

# define LIGHT_INVALID_POINTER "invalid (null) light pointer"

//	TYPEDEFS - forward declarations

typedef struct s_intersect_details	t_intersect_details;

// TYPEDEFS

typedef struct s_light
{
	t_point	position;
	t_color	intensity;
}	t_light;

// PROTOTYPES

t_light	*new_light(t_point position, t_color intensity);
t_light	set_light(t_point position, t_color intensity);
void	destroy_light(t_light *light);
t_color	lighting(t_intersect_details *details, t_light *light);

#endif

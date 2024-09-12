/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/12 22:12:39 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

//	INCLUDES

# include "minirt.h"

// DEFINES

# define LIGHT_INVALID_POINTER "invalid (null) light pointer"

# define LIGHT_DEFAULT_X -10
# define LIGHT_DEFAULT_Y 10
# define LIGHT_DEFAULT_Z -10
# define LIGHT_DEFAULT_R 1
# define LIGHT_DEFAULT_G 1
# define LIGHT_DEFAULT_B 1

// TYPEDEFS

typedef struct s_light
{
	t_point	position;
	t_color	intensity;
}			t_light;

// PROTOTYPES

t_light	*init_light(char **str);
t_light	*new_light(void);
t_light	set_light(t_point position, t_color intensity);
void	destroy_light(t_light *light);
t_color	lighting(t_details *details, t_light *light);

#endif

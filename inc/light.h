/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/27 14:04:29 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

//	INCLUDES

# include "minirt.h"

// TYPEDEFS

typedef struct s_light
{
	t_point	position;
	t_color	intensity;
}	t_light;

// PROTOTYPES

t_light	*new_light(t_point position, t_color intensity);
t_light	set_light(t_point position, t_color intensity);

#endif

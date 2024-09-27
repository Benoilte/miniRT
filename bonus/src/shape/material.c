/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:39:19 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/27 16:11:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	set_default_material(t_material *m)
{
	if (!m)
		return (shape_error("set_default_material", MATERIAL_INVALID_POINTER));
	m->color = rgb_itos(SH_DEFAULT_COLOR);
	m->ambient = m->color;
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->shininess = 200.0;
}

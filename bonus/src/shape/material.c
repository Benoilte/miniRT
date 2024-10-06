/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:39:19 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/01 18:14:29 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
	Indices of Refraction

	Vacuum: 1
	Air: 1.00029
	Water: 1.333
	Glass: 1.52
	Diamond: 2.417
*/

t_material	get_default_material(char **args)
{
	t_material	m;

	m.color = rgb_itos(MAT_DEFAULT_COLOR);
	m.ambient = m.color;
	m.diffuse = MAT_DEFAULT_DIFFUSE;
	m.specular = MAT_DEFAULT_SPECULAR;
	m.shininess = MAT_DEFAULT_SHININESS;
	m.reflective = MAT_DEFAULT_REFLECTIVE;
	m.transparency = MAT_DEFAULT_TRANSPARENCY;
	m.refractive_index = MAT_DEFAULT_REF_INDEX;
	if (args && count_args((const char **)args) == MATERIAL_PARAMS + 1)
	{
		m.diffuse = rt_roundf(ft_atod(args[1]));
		m.specular = rt_roundf(ft_atod(args[2]));
		m.shininess = rt_roundf(ft_atod(args[3]));
		m.reflective = rt_roundf(ft_atod(args[4]));
		m.transparency = rt_roundf(ft_atod(args[5]));
		m.refractive_index = rt_roundf(ft_atod(args[6]));
	}
	return (m);
}

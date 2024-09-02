/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:25:52 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 12:44:07 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//	INCLUDES

//	DEFINES

//	TYPEDEFS

typedef enum e_id
{
	ID_AMBIENT,
	ID_CAMERA,
	ID_LIGHT,
	ID_SPHERE,
	ID_PLANE,
	ID_CYLINDER,
	ID_COUNT
}	t_id;

typedef enum e_info
{
	INFO_ID,
	INFO_LIGHT,
	INFO_COLOR,
	INFO_COORD,
	INFO_NORM_VECTOR,
	INFO_FOV,
	INFO_SIZE
}	t_info;

typedef enum e_value_type
{
	VT_REAL_NUM,
	VT_RATIO,
	VT_POS_NUM,
	VT_UINT8,
	VT_FOV
}	t_value_type;

//	PROTOTYPES

#endif
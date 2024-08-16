/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:54:18 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/16 17:32:53 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "colors.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define SH_INVALID_ERROR "invalid shape type"

typedef enum e_shape_type
{
	SPHERE,
	SHAPE_COUNT
}	t_shape_type;

typedef struct s_shape_vtable
{
	void	(*destroy)(t_shape *self);
	// ...
}			t_shape_vtable;

typedef struct s_shape
{
	t_shape_type	type;
	void			*specs; // find better name
	t_shape_vtable	*f;
	t_color			color;
}					t_shape;

void	shape_error(const char *source, const char *msg);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_declarations.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:21:39 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/04 11:55:00 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORWARD_DECLARATIONS_H
# define FORWARD_DECLARATIONS_H

# include "libft.h"
# include "dlist.h"

typedef struct s_mlx				t_mlx;
typedef struct s_world				t_world;
typedef struct s_camera				t_camera;
typedef struct s_data				t_data;
typedef struct s_material			t_material;
typedef struct s_sphere				t_sphere;
typedef struct s_vtable				t_vtable;
typedef struct s_shape				t_shape;
typedef t_list						t_shape_list;
typedef enum e_shape_type			t_shape_type;
typedef struct s_ray				t_ray;
typedef struct s_light				t_light;
typedef struct s_intersection		t_intersection;
typedef struct s_intersect_details	t_intersect_details;
typedef struct s_intersect_report	t_intersect_report;
typedef t_dbl_lst					t_intersect_list;
typedef t_intersect_report			t_report;
typedef t_intersect_details			t_details;
typedef struct s_render_info        t_render_info;

#endif
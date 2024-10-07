/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:34:54 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 15:56:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//	INCLUDES

# include "minirt.h"

# include <pthread.h>
# include <sys/time.h>

//	DEFINES

# define DEFAULT_THREAD_COUNT	4
# define REFLECTIVE_DEPTH		5
# define REFRACTIVE_DEPTH		5

//	TYPEDEFS

typedef struct s_pixel
{
	int	x;
	int	y;
}		t_pixel;

typedef struct s_render_info
{
	int			thread_id;
	t_data		*data;
	int			start_line;
	int			stop_line;
	int			reflective_depth;
	int			refractive_depth;
	t_dbl_lst	*shape_container;
}				t_render_info;

typedef struct s_render
{
	t_render_info	*blocks;
	pthread_t		*threads;
	int				thread_count;
	pthread_mutex_t	print_lock;
}					t_render;

//	PROTOTYPES

void		set_pixel_color(t_data *data, int x, int y, int color);

void		render(t_data *data);
void		*render_strip(void *arg);
t_m4x4		view_transform(t_point from, t_vector forward, t_vector up);
t_camera	camera(size_t hsize, size_t vsize, float fov);
t_ray		ray_for_pixel(t_camera camera, size_t px, size_t py);
int			intersect_world(t_intersect_list **list, t_ray *ray, \
							t_world *world);
int			color_at(t_color *color, t_shape *self, t_ray *ray, \
							t_render_info *info);
int			is_shadowed(t_shape *self, t_world *world, t_point point, \
							t_details *details);
int			set_shadow(t_world *world, t_details *details);
int			reflected_color(t_color *color, t_render_info info, \
							t_details *details);
int			compute_final_color(t_color *color, t_details *details, \
									t_render_info info, t_dbl_lst *intersects);

	//	MULTI-THREADING
int			get_available_core_count(void);
void		create_threads(t_data *data);
void		join_threads(t_data *data);

void		timed_render(t_data *data);

#endif
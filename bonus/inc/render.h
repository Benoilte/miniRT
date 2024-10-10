/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:34:54 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/10 18:16:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//	INCLUDES

# include "minirt.h"

# include <pthread.h>
# include <sys/time.h>

//	DEFINES

# define DEFAULT_THREAD_COUNT		4
# define DEFAULT_REFLECTIVE_DEPTH	5
# define DEFAULT_REFRACTIVE_DEPTH	5

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
	int				master_reflective_depth;
	int				master_refractive_depth;
}					t_render;

//	PROTOTYPES

//	draw_utils.c
void		set_pixel_color(t_data *data, int x, int y, int color);

//	render.c
void		render(t_data *data);
void		*render_strip(void *arg);

//	camera.c
t_camera	camera(t_pixel resolution, float fov);
t_ray		ray_for_pixel(t_camera camera, size_t px, size_t py);

//	view_transform.c
t_m4x4		view_transform(t_point from, t_vector forward, t_vector up);

//	intersect_world.c
int			intersect_world(t_intersect_list **list, t_ray *ray, \
							t_world *world);

//	color_at.c
int			color_at(t_color *color, t_shape *self, t_ray *ray, \
							t_render_info *info);
int			compute_final_color(t_color *color, t_details *details, \
								t_render_info info, t_inter_lst *intersects);

//	shadow.c
int			is_shadowed(t_shape *self, t_world *world, t_point point, \
							t_details *details);
int			set_shadow(t_world *world, t_details *details);

//	reflection.c
int			reflected_color(t_color *color, t_render_info info, \
							t_details *details);
float		schlick_approximation(t_details *details);

//	multi_threading.c
void		create_threads(t_data *data);
int			join_threads(t_data *data);

//	multi_threading_utils.c
int			get_available_core_count(void);

void		timed_render(t_data *data);

#endif
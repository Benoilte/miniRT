/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:34:54 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/16 12:17:21 by bgolding         ###   ########.fr       */
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

# define AA_ONE_SAMPLE			1
# define AA_MEDIUM_SAMPLE		2
# define AA_ADAPTIVE_SAMPLE		3

# define TILE_WIDTH		32
# define TILE_HEIGHT	24

//	TYPEDEFS

typedef struct s_pixel
{
	int	x;
	int	y;
	float	x_offset;
	float	y_offset;
}		t_pixel;

typedef struct s_render_info
{
	int			thread_id;
	t_data		*data;
	int			start_line;
	int			stop_line;
	int			reflective_depth;
	int			refractive_depth;
	int			depth;
	int			aa_sample_precision;
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

// render_pixel.c
int			render_pixel(t_color *color, t_render_info *info, t_pixel *pixel);

//	camera.c
t_camera	camera(t_pixel resolution, float fov);
t_ray		ray_for_pixel(t_camera c, t_pixel *pixel);
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
int			create_threads(t_data *data);
int			join_threads(t_data *data);

//	multi_threading_utils.c
int			get_available_core_count(void);
int			report_threads_created(int created, int total);
int			report_threads_failed(int thread_error_count);

//	test/time.c
void		timed_render(t_data *data);

#endif

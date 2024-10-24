/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:34:54 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/24 16:02:41 by bgolding         ###   ########.fr       */
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

# define AA_ONE_SAMPLE				0
# define AA_MEDIUM_SAMPLE			1
# define AA_ADAPTIVE_SAMPLE			2

# define AA_SAMPLE_SIZE				4
# define AA_HALF_SAMPLE_SIZE		2
# define AA_DEPTH					4
# define AA_VARIANCE_TRESHOLD		0.0001

# define TILE_WIDTH		32
# define TILE_HEIGHT	24

//	TYPEDEFS

typedef struct s_pixel
{
	int		x;
	int		y;
	float	x_offset;
	float	y_offset;
}		t_pixel;

typedef struct s_tile
{
	t_pixel	start;
	t_pixel	end;
}			t_tile;

typedef struct s_render_info
{
	int			thread_id;
	t_data		*data;
	int			reflective_depth;
	int			refractive_depth;
	int			depth;
	int			aa_sample_precision;
	t_dbl_lst	*shape_container;
}				t_render_info;

typedef struct s_render
{
	t_list			*tile_stack;
	t_render_info	*blocks;
	pthread_t		*threads;
	int				thread_count;
	int				master_reflective_depth;
	int				master_refractive_depth;
	int				master_aa_precision;
}					t_render;

//	PROTOTYPES

//	draw_utils.c
void		set_pixel_color(t_data *data, int x, int y, int color);

//	render.c
void		render(t_data *data);
int			render_tile(t_render_info *info, t_tile *tile);
void		timed_render(t_data *data);

// render_pixel.c
int			render_pixel(t_color *color, t_render_info *info, t_pixel *pixel);
int			set_px_one_sample(t_color *color, t_render_info *info, t_pixel *px);

// render_adaptive_sample.c
int			set_px_adaptive_sample(t_color *color, t_render_info *info, \
																t_pixel *px);
//	camera.c
t_camera	camera(t_pixel resolution, float fov);
t_ray		ray_for_pixel(t_camera c, t_pixel *pixel);

//	view_transform.c
t_m4x4		view_transform(t_camera *camera);
t_vector	get_true_up(t_vector forward);
t_vector	get_left(t_vector forward, t_vector up);

//	intersect_world.c
int			intersect_world(t_intersect_list **list, t_ray *ray, \
							t_world *world);

//	color_at.c
int			color_at(t_color *color, t_details *prev_inter, t_ray *ray, \
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
void		multi_thread_render(t_data *data, t_thread_info *thread_info);
void		*thread_render_routine(void *arg);
int			create_threads(t_data *data);
int			join_threads(t_data *data);

//	multi_threading_utils.c
int			get_available_core_count(void);
int			report_threads_created(int created, int total);
int			report_threads_failed(int thread_error_count);
int			tile_stack_mutex(t_mutex_type type);

//	tiling.c
int			init_tile_stack(t_list **tile_stack, t_pixel end);
t_tile		*get_next_tile(t_list **tile_stack);
void		destroy_tile(void *content);

//	render_utils.c
void		initialize_render(t_data *data, t_thread_info *thread_info);
void		update_progress(t_data *data, int tile_finished);
int			display_rendered_image(t_data *data);
int			redirect_stderr_to_log_file(t_data *data);
int			restore_stderr(t_data *data);

#endif
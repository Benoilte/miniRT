/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:23:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/05 15:42:40 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//	STATIC LIBRARIES
# include "mlx.h"
# include "libft.h"
# include "libgraphic.h"
# include "dlist.h"

//	LOCAL HEADERS
# include "forward_declarations.h"
# include "hex_colors.h"
# include "parsing.h"
# include "ray.h"
# include "intersection.h"
# include "shape.h"
# include "light.h"

//	STANDARD LIBRARIES
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

//	DEFINES
# define WINDOW_NAME "miniRT"

# define INVALID_POINTER "invalid (null) pointer passed as argument"

//	OS specifics
# ifdef __APPLE__
#  include "macos_keycodes.h"
#  define WIN_WIDTH 960
#  define WIN_HEIGHT 720
#  define WIN_MID_X 480
#  define WIN_MID_Y 360
# endif

# ifdef __linux__
#  include "linux_keycodes.h"
#  include <X11/X.h>
#  define WIN_WIDTH 2048
#  define WIN_HEIGHT 1536
#  define WIN_MID_X 1024
#  define WIN_MID_Y 768
# endif

# define REFLECTIVE_DEPTH	5

// 	TYPEDEFS

typedef struct s_mlx
{
	void	*xvar;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
}			t_mlx;

typedef t_list					t_shape_list;

typedef struct s_world
{
	t_shape_list	*shapes;
	t_light			*light;
	t_color			ambient;
	t_material		default_material;
}					t_world;

typedef struct s_camera
{
	size_t	hsize;
	size_t	vsize;
	float	field_of_view;
	t_m4x4	transform;
	t_m4x4	transform_inverse;
	float	pixel_size;
	float	half_width;
	float	half_height;
}			t_camera;

typedef struct s_render_info
{
	int		thread_id;
	t_data	*data;
	int		start_line;
	int		stop_line;
	int		reflective_depth;
}			t_render_info;

typedef struct s_render
{
	t_render_info	*blocks;
	pthread_t		*threads;
	int				thread_count;
	pthread_mutex_t	print_lock;
}					t_render;

typedef struct s_data
{
	t_input_data	input;
	t_mlx			*mlx;
	t_world			*world;
	t_camera		*camera;
	t_render		render;
}					t_data;

typedef struct s_pixel
{
	int	x;
	int	y;
}		t_pixel;

//	PROTOTYPES

	//	ERROR HANDLING

int					input_error(t_input_data *input, const char *source, \
															const char *msg);
int					log_error(t_list **errors, int type, int line);
void				exit_error(t_data *data, char *message);
int					print_error(const char *source, const char *msg);

	//	DATA

int					init_input(t_input_data *input, int argc, char **argv);
t_data				*init_data(int argc, char **argv);
t_world				*init_world(t_list *token_list);
t_camera			*init_camera(char **str);
int					init_render_settings(t_data *data, t_render *render);
void				destroy_input(t_input_data *input);
void				destroy_data(t_data *data);
void				destroy_world(t_world *world);
void				destroy_camera(t_camera *camera);
void				destroy_render_settings(t_render *render);
t_shape				*add_new_shape_to_world(t_world *world, t_shape_type type);
char				**get_element(t_list *token_list, t_id id);
float				rt_roundf(float val);
t_tuple				str_to_tuple(char *str, int type);
t_color				str_to_rgb(char *str);
t_color				get_ambient(char **str);

	//	WINDOW (MLX)

t_mlx				*init_mlx(void);
void				destroy_mlx(t_mlx *mlx);
int					close_minirt(t_data *data);
void				reset_image(t_data *data);

	//	HOOKS

void				set_hooks(t_data *data);
int					keypress(int keycode, t_data *data);
int					mouse_down(int keycode, t_data *data);
int					mouse_up(int keycode, t_data *data);
int					mouse_move(int x, int y, t_data *data);

	//	DRAW_UTILS

void				set_pixel_color(t_data *data, int x, int y, int color);

	//	RENDER

void				render(t_data *data);
t_m4x4				view_transform(t_point from, t_vector forward, t_vector up);
t_camera			camera(size_t hsize, size_t vsize, float fov);
t_ray				ray_for_pixel(t_camera camera, size_t px, size_t py);
int					intersect_world(t_intersect_list **list, t_ray *ray, \
									t_world *world);
int					color_at(t_color *color, t_shape *self, t_ray *ray, \
									t_render_info *info);
int					reflected_color(t_color *color, t_render_info *info, \
									t_details *details);
int					compute_final_color(t_color *color, t_details *details, \
									t_render_info *info);

	//	MULTI-THREADING
int					get_available_core_count(void);

	// TEST

void				print_color(t_color c, char *msg);
void				timed_render(t_data *data);

#endif

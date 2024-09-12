/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:23:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 16:54:26 by bgolding         ###   ########.fr       */
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

//	DEFINES
# define WINDOW_NAME "miniRT"

# define INVALID_POINTER "invalid (null) pointer passed as argument"

//	OS specifics
# ifdef __APPLE__
#  include "macos_keycodes.h"
#  define WIN_WIDTH 1800
#  define WIN_HEIGHT 1200
#  define WIN_MID_X 800
#  define WIN_MID_Y 600
#  define LINUX 0
# endif

# ifdef __linux__
#  include "linux_keycodes.h"
#  include <X11/X.h>
#  define LINUX 1
#  define WIN_WIDTH 2400
#  define WIN_HEIGHT 1600
#  define WIN_MID_X 1200
#  define WIN_MID_Y 800
# endif

# define CAMERA_DEFAULT_FOV 90

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

typedef struct s_data
{
	t_input_data	input;
	t_mlx			*mlx;
	t_world			*world;
	t_camera		*camera;
}					t_data;

//	PROTOTYPES

	//	ERROR HANDLING

int					input_error(t_input_data *input, const char *source, \
															const char *msg);
int					log_error(t_list **errors, int type, int line);
void				exit_error(t_data *data, char *message);
void				print_error(const char *source, const char *msg);

	//	DATA

int					init_input(t_input_data *input, int argc, char **argv);
t_data				*init_data(int argc, char **argv);
t_world				*init_world(void);
t_camera			*init_camera(char **str);
void				destroy_input(t_input_data *input);
void				destroy_data(t_data *data);
void				destroy_world(t_world *world);
void				destroy_camera(t_camera *camera);
int					add_new_shape_to_world(t_world *world, t_shape_type type);
char				**get_element(t_list *token_list, t_id id);
t_tuple				str_to_tuple(char *str, int type);

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
t_m4x4				view_transform(t_point from, t_point to, t_vector up);
t_camera			camera(size_t hsize, size_t vsize, float fov);
t_ray				ray_for_pixel(t_camera camera, size_t px, size_t py);
t_intersect_list	*intersect_world(t_ray *r, t_world *world);
t_color				color_at(t_ray *ray, t_world *world);

	// TEST

void				print_color(t_color c, char *msg);

#endif

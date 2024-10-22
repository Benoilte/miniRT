/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:23:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 18:58:57 by bebrandt         ###   ########.fr       */
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
# include "error_handling.h"
# include "parsing.h"
# include "render.h"
# include "ray.h"
# include "intersection.h"
# include "shape.h"
# include "light.h"
# include "refraction.h"
# include "controls.h"

//	STANDARD LIBRARIES
# include <errno.h>
# include <string.h>
# include <stdio.h>

//	DEFINES
# define WINDOW_NAME "miniRT"

//	OS specifics
# ifdef __APPLE__
#  include "macos_keycodes.h"
#  define DEFAULT_WIN_WIDTH 960
#  define DEFAULT_WIN_HEIGHT 720
# endif

# ifdef __linux__
#  include "linux_keycodes.h"
#  include <X11/X.h>
#  define DEFAULT_WIN_WIDTH 2048
#  define DEFAULT_WIN_HEIGHT 1536
# endif

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

typedef struct s_world
{
	t_shape_list	*shapes;
	t_light			*light;
	t_color			ambient;
	t_material		default_material;
}					t_world;

typedef struct s_camera
{
	t_point		from;
	t_vector	forward;
	t_vector	up;
	float		field_of_view;
	t_m4x4		transform;
	t_m4x4		transform_inverse;
	float		pixel_size;
	float		half_width;
	float		half_height;
}				t_camera;

typedef struct s_err_fds
{
	int	stderr_cpy;
	int	err_log;
}		t_err_fds;

typedef struct s_data
{
	t_input_data	input;
	t_mlx			*mlx;
	t_world			*world;
	t_camera		*camera;
	t_render		render;
	t_pixel			resolution;
	t_err_fds		fd;
}					t_data;

//	PROTOTYPES - DATA

//	init_data.c
t_data		*init_data(int argc, char **argv);

//	init_world.c
t_world		*init_world(t_list *token_list);
t_shape		*add_new_shape_to_world(t_world *world, t_shape_type type);

//	init_input.c
int			init_input(t_input_data *input, int argc, char **argv);

//	init_render.c
int			init_render_settings(t_data *data, t_render *render);

//	init_utils.c
char		**get_element(t_list *token_list, t_id id);
float		rt_roundf(float val);
t_tuple		str_to_tuple(char *str, int type);
t_color		str_to_rgb(char *str);
t_color		get_ambient(char **str);

//	destroy_data.c
void		destroy_data(t_data *data);

//	destroy_world.c
void		destroy_world(t_world *world);

//	destroy_input.c
void		destroy_input(t_input_data *input);

//	destroy_render.c
void		destroy_render_settings(t_render *render);

//	render/camera.c
t_camera	*init_camera(t_data *data);
void		destroy_camera(t_camera *camera);

//	PROTOTYPES - WINDOW (MLX)

//	init_mlx.c
t_mlx		*init_mlx(t_pixel resolution);
void		reset_image(t_data *data);

//	destroy_mlx_[linux|macos].c
void		destroy_mlx(t_mlx *mlx);
//	close_[linux|macos].c
int			close_minirt(t_data *data);

//	PROTOTYPES HELPER

//	helper.c
void		helper(void);

//	PROTOTYPES - TESTS

void		print_color(t_color c, char *msg);

#endif

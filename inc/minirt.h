/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:23:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/27 15:50:16 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//	LIBRARIES
# include "mlx.h"
# include "libft.h"
# include "libgraphic.h"
# include "dlist.h"
# include "hex_colors.h"
# include "ray.h"
# include "shape.h"
# include "intersection.h"
# include <errno.h>
# include <stdio.h>

//	DEFINES
# define WINDOW_NAME "miniRT"

//	OS specifics
# ifdef __APPLE__
#  include "macos_keycodes.h"
#  define WIN_WIDTH (1800)
#  define WIN_HEIGHT (1200)
#  define WIN_MID_X (800)
#  define WIN_MID_Y (600)
#  define LINUX (0)
# elif defined __linux__
#  include "linux_keycodes.h"
#  include <X11/X.h>
#  define LINUX (1)
#  define WIN_WIDTH (2400)
#  define WIN_HEIGHT (1600)
#  define WIN_MID_X (1200)
#  define WIN_MID_Y (800)
# endif

//	TYPEDEFS - forward declarations

typedef enum e_shape_type t_shape_type;

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

typedef t_list	t_shape_list;

typedef struct s_world
{
	t_shape_list	*shapes;
}					t_world;

typedef struct s_data
{
	t_mlx	*mlx;
	t_world	*world;
}			t_data;

//	PROTOTYPES

	//	ERROR HANDLING

void	exit_error(t_data *data, char *message);

	//	DATA

t_data	*init_data(void);
t_world	*init_world(void);
void	destroy_data(t_data *data);
void	destroy_world(t_world *world);
int		add_new_shape_to_world(t_world *world, t_shape_type type);

	//	WINDOW (MLX)
	
t_mlx	*init_mlx(void);
void	destroy_mlx(t_mlx *mlx);
int		close_minirt(t_data *data);
void	reset_image(t_data *data);

	//	HOOKS

void	set_hooks(t_data *data);
int		keypress(int keycode, t_data *data);
int		mouse_down(int keycode, t_data *data);
int		mouse_up(int keycode, t_data *data);
int		mouse_move(int x, int y, t_data *data);

	//	DRAW_UTILS

void	set_pixel_color(t_data *data, int x, int y, int color);

	//	RENDER

void	render(t_data *data);

#endif
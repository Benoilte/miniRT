/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:39:06 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/22 09:38:56 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# define CAM_ROTATE_DEGREES 15

typedef enum e_control_mode
{
	MODE_BASE	= 0,
	MODE_CAMERA,
	MODE_SHAPE,
	MODE_LIGHT,
}	t_control_mode;

typedef enum e_editor_value
{
	OFF,
	ON
}	t_editor_value;

typedef enum e_direction
{
	FORWARD,
	BACK,
	RIGHT,
	LEFT,
	UP,
	DOWN
}	t_direction;

typedef enum e_camera_rotate
{
	PITCH_UP,
	PITCH_DOWN,
	YAW_LEFT,
	YAW_RIGHT,
	ROLL_RIGHT,
	ROLL_LEFT
}	t_camera_rotate;

//	hooks.c
void			set_hooks(t_data *data);

//	keypress.c
int				keypress(int keycode, t_data *data);
bool			is_movement_key(int key);
bool			is_rotation_key(int key);
bool			is_control_key(int key);

//	mouse.c
int				mouse_down(int button, int x, int y, t_data *data);

//	mode.c
int				get_mode(void);
int				toggle_mode(int toggle);
bool			editor_is(t_editor_value value);

//	camera_controls.c
void			apply_camera_control(int keycode, t_camera *camera);

//	key_utils.c
bool			is_movement_key(int key);
bool			is_rotation_key(int key);
bool			is_control_key(int key);
t_direction		get_direction(int keycode);
t_camera_rotate	get_rotate_type(int keycode);

//	shape_selection.c
t_shape			*select_shape(int x, int y, t_data *data);
void			set_selected_shape(t_shape *new);
t_shape			*get_selected_shape(void);

#endif
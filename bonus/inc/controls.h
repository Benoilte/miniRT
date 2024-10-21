/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:39:06 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/21 16:20:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

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

typedef enum t_movement
{
	PITCH_UP,
	PITCH_DOWN,
	YAW_LEFT,
	YAW_RIGHT,
	ROLL_RIGHT,
	ROLL_LEFT
}	t_movement;

//	mode.c
int		get_mode(void);
int		toggle_mode(int toggle);
bool	editor_is(t_editor_value value);

//	camera_controls.c
void	apply_camera_control(int keycode, t_camera *camera);

#endif
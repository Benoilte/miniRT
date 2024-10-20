/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:39:06 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/20 17:15:20 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

typedef enum e_control_mode
{
	MODE_BASE	= 0,
	MODE_CAMERA	= 1 << 0,
	MODE_SHAPE	= 1 << 1,
	MODE_LIGHT	= 1 << 2
}	t_control_mode;

typedef enum e_direction
{
	FORWARD,
	BACK,
	RIGHT,
	LEFT,
	UP,
	DOWN
}	t_direction;

//	mode.c
int		get_mode(void);
int		toggle_mode(int toggle);

//	camera_controls.c
void	apply_camera_control(int keycode, t_camera *camera);

#endif
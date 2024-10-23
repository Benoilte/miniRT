/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:39:36 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/23 09:39:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

//	INCLUDES

# include <stdbool.h>

// DEFINES

# define EXIT_TITLE			"How to exit program"
# define EDITOR_TITLE		"How to use editor mode"
# define RENDER_TITLE		"How to use render setting mode"
# define MOVE_KEY_TITLE		"\tMovement Key"
# define ROT_KEY_TITLE		"\tRotation key"
# define CAMERA_MOVE_TITLE	"\tHow to move CAMERA"
# define SHAPE_MOVE_TITLE	"\tHow to move SHAPE"
# define LIGHT_MOVE_TITLE	"\tHow to move LIGHT"

# define TAB_PRESS_KEY		"\tPress on key "
# define TAB_TAB_PRESS_KEY	"\t\tPress on key "
# define TAB_TAB_PRESS_NUM	"\t\tPress on numpad key "
# define TAB_PRESS_ON		"\tPress on the "

//	PROTOTYPES HELPER

//	man_minirt.c
void	man_minirt(void);
void	man_exit_minirt(void);
void	print_title(char *title);
void	print_bold_italic(char *msg, char *bold_italic);
void	print_help_msg(void);

//	man_editor.c
void	man_editor(void);
void	man_camera_mode(void);
void	man_shape_select_mode(void);
void	man_light_mode(void);

//	man_render_settings.c
void	man_render_settings(void);


//	man_utils.c
void	print_movement(char *mode);
void	print_rotation(void);

#endif

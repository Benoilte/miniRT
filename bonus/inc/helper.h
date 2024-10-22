/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:39:36 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/23 00:47:09 by bebrandt         ###   ########.fr       */
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
# define CAMERA_MOVE_TITLE	"\tHow to move CAMERA"
# define CAMERA_ROT_TITLE	"\tHow to rotate CAMERA"
# define SHAPE_MOVE_TITLE	"\tHow to move SHAPE"
# define SHAPE_ROT_TITLE	"\tHow to rotate SHAPE"

# define TAB_PRESS_KEY		"\tPress on key "
# define TAB_TAB_PRESS_KEY	"\t\tPress on key "
# define TAB_TAB_PRESS_NUM	"\t\tPress on numpad key "
# define PRESS_ON			"\tPress on the "

# define HELP_MSG			"Press H key for help"

//	PROTOTYPES HELPER

//	helper.c
void	man_minirt(void);
void	man_exit_minirt(void);
void	print_title(char *title);
void	print_bold_italic(char *msg, char *bold_italic);

//	helper_uils.c
void	man_editor(void);
void	man_render_settings(void);

#endif

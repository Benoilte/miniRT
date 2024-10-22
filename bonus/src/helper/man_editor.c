/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:48:22 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/23 00:58:30 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
	YAW_LEFT = spin left
	YAW_RIGHT = spin right
	PITCH_UP = tilt up
	PITCH_DOWN = tilt down
	ROLL_LEFT = tilt left
	ROLL_RIGHT = tilt right

    YAW     :       LEFT (4) | RIGHT (6)
    PITCH   :       UP (8) | DOWN (5)
    ROLL    :       LEFT (7) | RIGHT (9)

	Added: RIGHT (D) LEFT (A) UP (E) and DOWN (Q) controls
	FORWARD (W) | BACK (S)
*/

static void	print_movement(char *mode)
{
	print_bold_italic(TAB_TAB_PRESS_KEY, "W");
	ft_printf(" to move %s FORWARD\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "S");
	ft_printf(" to move %s BACKWARD\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "D");
	ft_printf(" to move %s RIGHT\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "A");
	ft_printf(" to move %s LEFT\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "E");
	ft_printf(" to move %s UP\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "Q");
	ft_printf(" to move %s DOWN\n", mode);
}

/*
	YAW_LEFT = spin left
	YAW_RIGHT = spin right
	PITCH_UP = tilt up
	PITCH_DOWN = tilt down
	ROLL_LEFT = tilt left
	ROLL_RIGHT = tilt right

    YAW     :       LEFT (4) | RIGHT (6)
    PITCH   :       UP (8) | DOWN (5)
    ROLL    :       LEFT (7) | RIGHT (9)
*/

static void	print_rotation(void)
{
	print_bold_italic(TAB_TAB_PRESS_NUM, "4");
	ft_printf(" to SPIN LEFT\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "6");
	ft_printf(" to SPIN RIGHT\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "8");
	ft_printf(" to TILT UP\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "5");
	ft_printf(" to TILT DOWN\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "7");
	ft_printf(" to TILT LEFT\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "9");
	ft_printf(" to TILT RIGHT\n");
}

void	man_shape_select_mode(void)
{
	print_title(SHAPE_MOVE_TITLE);
	ft_printf("\t\tClick on a shape to select it\n");
	print_movement("shape");
}

void	man_camera_mode(void)
{
	print_title(CAMERA_MOVE_TITLE);
	print_movement("camera");
	print_title(CAMERA_ROT_TITLE);
	print_rotation();
}

void	man_editor(void)
{
	print_title(EDITOR_TITLE);
	print_bold_italic(TAB_PRESS_KEY, "E");
	ft_printf(" to activate EDITOR and display a simple render.\n");
	ft_printf("\tBy default, you start in CAMERA mode.\n");
	print_bold_italic(TAB_PRESS_KEY, "TAB");
	ft_printf(" to switch between CAMERA | SHAPE | LIGHT mode\n");
	print_bold_italic(TAB_PRESS_KEY, "ENTER");
	ft_printf(" to exit EDITOR and display a full render\n");
	man_camera_mode();
	man_shape_select_mode();
}

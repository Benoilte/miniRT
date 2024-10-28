/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:48:22 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/23 01:57:53 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	man_shape_select_mode(void)
{
	print_title(SHAPE_MOVE_TITLE);
	print_bold_italic(TAB_TAB_PRESS_KEY, "TAB");
	ft_printf(" and select the SHAPE SELECT mode\n");
	ft_printf("\t\tClick on a shape to select it");
	ft_printf(" and move it according to the movement key\n");
	ft_printf("\t\tShape rotation will be implemented later\n");
}

void	man_camera_mode(void)
{
	print_title(CAMERA_MOVE_TITLE);
	print_bold_italic(TAB_TAB_PRESS_KEY, "TAB");
	ft_printf(" and select the CAMERA mode\n");
	ft_printf("\t\tMove it according to the movement and rotation key\n");
}

void	man_light_mode(void)
{
	print_title(LIGHT_MOVE_TITLE);
	print_bold_italic(TAB_TAB_PRESS_KEY, "TAB");
	ft_printf(" and select the LIGHT mode\n");
	ft_printf("\t\tMove it according to the movement key\n");
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
	print_title(MOVE_KEY_TITLE);
	print_movement("object");
	print_title(ROT_KEY_TITLE);
	print_rotation();
	man_camera_mode();
	man_shape_select_mode();
	man_light_mode();
}

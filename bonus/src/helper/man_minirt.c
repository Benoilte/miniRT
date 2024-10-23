/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_minirt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:30:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/23 09:40:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_help_msg(void)
{
	print_bold_italic(TAB_PRESS_KEY, "H");
	ft_printf(" for help\n");
}

void	print_bold_italic(char *msg, char *bold_italic)
{
	ft_printf("%s\033[1m\033[3m%s\033[0m\033[0m", msg, bold_italic);
}

void	print_title(char *title)
{
	ft_printf("\n\033[1m\033[4m%s\033[0m\n\n", title);
}

void	man_exit_minirt(void)
{
	print_title(EXIT_TITLE);
	print_bold_italic(TAB_PRESS_KEY, "ESC\n");
	print_bold_italic(TAB_PRESS_ON, "window cross\n");
}

void	man_minirt(void)
{
	print_title("\n\033[0;33mHOW TO USE MINIRT PROGRAM");
	man_editor();
	man_render_settings();
	man_exit_minirt();
}

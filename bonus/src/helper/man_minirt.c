/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_minirt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:30:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/24 10:37:06 by bebrandt         ###   ########.fr       */
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
	ft_printf("%s"BOLD ITALIC"%s"RESET_FONT, msg, bold_italic);
}

void	print_title(char *title)
{
	ft_printf("\n"BOLD UNDERLINE"%s"RESET_FONT"\n\n", title);
}

void	man_exit_minirt(void)
{
	print_title(EXIT_TITLE);
	print_bold_italic(TAB_PRESS_KEY, "ESC\n");
	print_bold_italic(TAB_PRESS_ON, "window cross\n");
}

int	man_minirt(void)
{
	print_title(MINIRT_TITLE);
	man_editor();
	man_render_settings();
	man_exit_minirt();
	return (0);
}

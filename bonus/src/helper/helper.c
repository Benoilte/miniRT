/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:30:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/22 19:09:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_bold_italic(char *msg, char *bold_italic)
{
	ft_printf("\t%s \033[1m\033[3m%s\033[0m\033[0m\n", msg, bold_italic);
}

static void	print_title(char *title)
{
	ft_printf("\n\033[1m\033[4m%s\033[0m\n\n", title);
}

void	helper(void)
{
	ft_printf("\n\033[0;33mHOW TO USE MINIRT PROGRAM\033[0m\n");
	print_title("How to exit program");
	print_bold_italic("Press on keyboard", "ESC");
	print_bold_italic("Press on the", "window cross");
	print_title("How to use editor mode");
	print_bold_italic("Press on keyboard", "E");
	print_title("How to use render setting mode");
	print_bold_italic("Press on keyboard", "R");
	print_title("How to redisplay this helper manual");
	print_bold_italic("Press on keyboard", "H");
}

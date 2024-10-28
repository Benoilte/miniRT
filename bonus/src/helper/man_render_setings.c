/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_render_setings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:45:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/23 01:24:07 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	man_render_settings(void)
{
	print_title(RENDER_TITLE);
	print_bold_italic(TAB_PRESS_KEY, "R");
	ft_printf(" to activate RENDER SETTINGS mode.\n");
	print_bold_italic(TAB_PRESS_KEY, "A");
	ft_printf(" to modify anti-aliasing precision range from 0 to 2\n");
	print_bold_italic(TAB_PRESS_KEY, "Q");
	ft_printf(" to modify Reflective depth range from 0 to 20\n");
	print_bold_italic(TAB_PRESS_KEY, "W");
	ft_printf(" to modify Refractive depth range from 0 to 20\n");
	print_bold_italic(TAB_PRESS_KEY, "ENTER");
	ft_printf(" to exit RENDER SETTINGS mode and display the modification.\n");
}

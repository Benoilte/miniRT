/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_render_setings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:45:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/23 00:45:28 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	man_render_settings(void)
{
	print_title(RENDER_TITLE);
	print_bold_italic(TAB_PRESS_KEY, "R\n");
}

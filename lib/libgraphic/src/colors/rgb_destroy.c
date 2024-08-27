/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:49:33 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/27 16:03:25 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

void	rgb_destroy(t_color	*color)
{
	if (!color)
		return (rgb_error("rgb_destroy", RGB_INVALID_POINTER));
	free(color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:28:00 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/27 17:29:44 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void	destroy_light(t_light *light)
{
	if (!light)
		print_error("destroy_light", LIGHT_INVALID_POINTER);
	free(light);
}

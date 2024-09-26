/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_macos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:26:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/27 15:50:27 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_minirt(t_data *data)
{
	printf("Closing miniRT ...\n");
	destroy_data(data);
	exit(EXIT_SUCCESS);
}

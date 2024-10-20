/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:06:46 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/20 16:09:41 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		return (close_minirt(data));
	return (0);
}

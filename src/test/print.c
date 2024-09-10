/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:06:53 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/10 16:21:53 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_color(t_color c, char *msg)
{
	printf("\t%-10s: rd: %- 10.5f green: %- 10.5f ", msg, c.red, c.green);
	printf("blue: %- 10.5f\n", c.blue);
}

void	print_tuple(t_tuple a, char *msg)
{
	printf("\t%-20s: x: %- 10.5f y: %- 10.5f ", msg, a.x, a.y);
	printf("z: %- 10.5f w: %- 10.5f\n", a.z, a.w);
}

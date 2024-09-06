/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:06:53 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/06 14:46:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_color(t_color c, char *msg)
{
	printf("\t%-10s: rd: %- 10.5f green: %- 10.5f ", msg, c.red, c.green);
	printf("blue: %- 10.5f\n", c.blue);
}

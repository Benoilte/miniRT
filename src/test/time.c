/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:53:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/25 12:08:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <time.h>

void	timed_render(t_data *data)
{
	clock_t	start;
	double	end;

	start = clock();
	render(data);
	end = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("Render time: %.2f seconds\n", end);
}

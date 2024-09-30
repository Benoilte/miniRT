/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:53:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/30 18:59:25 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	timed_render(t_data *data)
{
	struct timeval	start;
	struct timeval	end;
	size_t			ms;
	float			seconds;

	gettimeofday(&start, NULL);
	render(data);
	gettimeofday(&end, NULL);
	ms = (end.tv_sec - start.tv_sec) * 1000 \
					+ (end.tv_usec / 1000 - start.tv_usec / 1000);
	seconds = (float)ms / 1000;
	printf("Render time: %.3f seconds\n", seconds);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:22:21 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 12:49:41 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_available_core_count(void)
{
	const int	default_cores = DEFAULT_THREAD_COUNT;
	int			online_cores;

	online_cores = sysconf(_SC_NPROCESSORS_ONLN);
	if (online_cores == -1)
	{
		perror("sysconf");
		return (default_cores);
	}
	return (online_cores);
}

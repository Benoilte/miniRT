/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:22:21 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 15:06:54 by bgolding         ###   ########.fr       */
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
		ft_putendl_fd(CORE_COUNT_ERROR, STDERR_FILENO);
		return (default_cores);
	}
	ft_printf("Online CPU cores detected: %d\n", online_cores);
	return (online_cores);
}

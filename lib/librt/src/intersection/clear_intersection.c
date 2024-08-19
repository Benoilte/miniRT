/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:52:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/19 12:00:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "intersection.h"

void	clear_intersection(void *intersection)
{
	free(intersection);
}

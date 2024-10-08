/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shape_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:58:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/08 13:30:05 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

float	ft_get_max_f(float x, float y, float z)
{
	if ((x > y) && (x > z))
		return (x);
	if ((y > x) && (y > z))
		return (y);
	else
		return (z);
}

float	ft_get_min_f(float x, float y, float z)
{
	if ((x < y) && (x < z))
		return (x);
	if ((y < x) && (y < z))
		return (y);
	else
		return (z);
}

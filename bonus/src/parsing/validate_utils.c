/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:49:31 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/07 17:51:32 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_real_num(const char *str)
{
	int	sign_count;
	int	dot_count;
	int	digit_present;

	if (!str)
		return (0);
	sign_count = 0;
	dot_count = 0;
	digit_present = 0;
	while (*str)
	{
		if (*str == '-' || *str == '+')
			sign_count++;
		else if (*str == '.')
			dot_count++;
		else if (ft_isdigit(*str))
			digit_present = 1;
		else
			return (0);
		if (sign_count > 1 || dot_count > 1)
			return (0);
		str++;
	}
	return (digit_present);
}

int	only_digits(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	in_range(float num, float min, float max)
{
	if (num >= min && num <= max)
		return (1);
	return (0);
}

int	validate_info(const char *str, int line, t_info info, t_list **errors)
{
	const t_validate_str	validate[INFO_COUNT] = {
		validate_brightness,
		validate_color,
		validate_coordinate,
		validate_vector,
		validate_fov,
		validate_size,
		validate_diffuse,
		validate_specular,
		validate_shininess,
		validate_reflective,
		validate_transparency,
		validate_refraction_index,
		validate_window_width,
		validate_window_height
	};

	if (info < 0 || info >= INFO_COUNT)
		return (-1);
	return (validate[info](str, line, errors));
}

int	count_args(const char **args)
{
	int	count;

	count = 0;
	if (args)
	{
		while (args[count])
			count++;
	}
	return (count);
}

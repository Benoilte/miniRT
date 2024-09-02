/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:12:59 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 15:37:37 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	invalid_filename(const char *filename)
{
	int	len;
	int	min_len;

	len = ft_strlen(filename);
	min_len = LX_SUFFIX_LEN + 1;
	if (len < min_len)
		return (1);
	if (!ft_strncmp(&filename[len - min_len], LX_SUFFIX, LX_SUFFIX_LEN))
		return (2);
	return (0);
}

int	validate_file(const char *filename, int *fd)
{
	if (!filename || !fd)
	{
		print_error("validate_file", LX_INVALID_PTR);
		return (1);
	}
	if (invalid_filename(filename))
	{
		print_error("validate_file", LX_INVALID_FILENAME);
		return (2);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		print_error("validate_file", strerror(errno));
		return (3);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:12:59 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 15:16:53 by bgolding         ###   ########.fr       */
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
	if (ft_strncmp(&filename[len - LX_SUFFIX_LEN], LX_SUFFIX, LX_SUFFIX_LEN))
		return (2);
	return (0);
}

int	validate_file(const char *filename, int *fd)
{
	if (!filename || !fd)
		return (input_error(NULL, "validate_file", INVALID_POINTER));
	if (invalid_filename(filename))
		return (input_error(NULL, "validate_file", INPUT_ERR_FILENAME));
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (input_error(NULL, "validate_file", strerror(errno)));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:46:39 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 10:06:05 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	leftovers[FD_LIMIT][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > FD_LIMIT || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= FD_LIMIT)
			gnl_clean_up(NULL, leftovers[fd]);
		return (NULL);
	}
	line = gnl_leftover_line(leftovers[fd]);
	if (!line)
		return (NULL);
	if (!ft_strchr(line, '\n'))
		line = gnl_read_new_line(fd, line, leftovers[fd]);
	if (!line)
		return (NULL);
	if (*line == '\0')
		return (gnl_clean_up(line, leftovers[fd]));
	return (line);
}

char	*gnl_read_new_line(int fd, char *line, char *leftovers)
{
	t_reader	r;
	char		*p;

	p = NULL;
	r.bytes_read = BUFFER_SIZE;
	while (!p && r.bytes_read == BUFFER_SIZE)
	{
		r.bytes_read = read(fd, r.buffer, BUFFER_SIZE);
		if (r.bytes_read == -1)
			return (gnl_clean_up(line, leftovers));
		r.buffer[r.bytes_read] = '\0';
		p = ft_strchr(r.buffer, '\n');
		if (p)
		{
			ft_strcpy(leftovers, p + 1);
			r.bytes_to_cat = p - r.buffer + 1;
		}
		else
			r.bytes_to_cat = r.bytes_read;
		line = gnl_free_cat(line, r.buffer, r.bytes_to_cat);
		if (!line)
			return (NULL);
	}
	return (line);
}

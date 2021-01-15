/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:58:22 by emurky            #+#    #+#             */
/*   Updated: 2021/01/04 12:58:28 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#define FDS				100

/*
**		FDS - number of file descriptors that could be opened in one time
*/

int		nl_finder(char **buffer, char **line)
{
	char	*nl_ptr;

	if ((nl_ptr = ft_strchr(*buffer, '\n')))
	{
		*nl_ptr++ = '\0';
		*line = ft_strjoin(*line, *buffer);
		ft_memmove(*buffer, nl_ptr, BUFFER_SIZE - (nl_ptr - *buffer) + 1);
		return (1);
	}
	*line = ft_strjoin(*line, *buffer);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer[FDS];
	int				read_count;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup("");
	if (!(buffer[fd]))
	{
		if (!(buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	else if (nl_finder(&(buffer[fd]), line))
		return (1);
	while ((read_count = read(fd, buffer[fd], BUFFER_SIZE)))
	{
		buffer[fd][read_count] = '\0';
		if (nl_finder(&(buffer[fd]), line))
			return (1);
	}
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (0);
}

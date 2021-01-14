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

#include "get_next_line.h"

# define BUFFER_SIZE	6 /*DELEEEEEEEEEETE*/
# define FDS			1

int		buffer_handling(char **buffer, char **line)
{
	char	*nl_pointer;

	if ((nl_pointer = ft_strchr(*buffer, '\n')))
	{
		*nl_pointer = '\0';
		*line = ft_strjoin(*line, *buffer);
		ft_memmove(*buffer, ++nl_pointer, BUFFER_SIZE);
		return (1);
	}
	*line = ft_strjoin(*line, *buffer);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer[FDS];
//	char			*nl_pointer;
	ssize_t			read_count;

	*line = ft_strdup("\0");
	if (!buffer[fd] && !(buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	else
		if (buffer_handling(&(buffer[fd]), line))
			return (1);
	while ((read_count = read(fd, buffer[fd], BUFFER_SIZE)))
	{
		buffer[fd][read_count] = '\0';
		if (buffer_handling(&(buffer[fd]), line))
			break ;
//		*line = buffer[fd];
	}
	return (1);
}

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

# define BUFFER_SIZE 32 /*DELEEEEEEEEEETE*/

int		get_next_line(int fd, char **line)
{
	static char		*buffer[128];
	char			*nl_pointer;
	ssize_t			read_count;
	
//	char *  a, b;

	if (!(buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (((read_count = read(fd, buffer[fd], BUFFER_SIZE)) == -1))
		return (-1);
	if ((nl_pointer = ft_strchr(buffer[fd], '\n')))
	{
		*nl_pointer = '\0';
//		buffer[fd] = ++nl_pointer;
	}
	buffer[fd][read_count] = '\0';
	*line = buffer[fd];
	return (1);
}

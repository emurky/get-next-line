/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:58:43 by emurky            #+#    #+#             */
/*   Updated: 2021/01/04 12:58:45 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char *end;

	end = s;
	while (*end)
		end++;
	return (end - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s || c == '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char *s2;
	char *strdup;

	if (!(s2 = malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	strdup = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (strdup);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstptr;
	const char	*srcptr;

	dstptr = dst;
	srcptr = src;
	if (dstptr == srcptr)
		return (dst);
	else if (dstptr < srcptr)
		while (len--)
			*dstptr++ = *srcptr++;
	else
	{
		dstptr += len;
		srcptr += len;
		while (len--)
			*(--dstptr) = *(--srcptr);
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	char	*s1_ptr;
	size_t	len;

	if (!(s1 && s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(joined_str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	joined_str[len] = '\0';
	s1_ptr = s1;
	while (*s1_ptr)
		*joined_str++ = *s1_ptr++;
	while (*s2)
		*joined_str++ = *s2++;
	free(s1);
	s1 = NULL;
	return (joined_str - len);
}

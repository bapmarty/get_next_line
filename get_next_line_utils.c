/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:42:35 by bapmarti          #+#    #+#             */
/*   Updated: 2020/01/13 18:01:53 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len;
	char	*s;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s[i] = s1[i];
	 	i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		s[i] = s2[i];
		i++;
	}
	s1 = s;
	return (s1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (!(newstr = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start < ft_strlen(s))
		while (i < len && s[i] != '\0')
		{
			newstr[i] = s[start + i];
			i++;
		}
	newstr[i] = '\0';
	return (newstr);
}

void	*ft_bzero(void *s, size_t n)
{
	unsigned char *p;

	p = s;
	while (n-- > 0)
		*p++ = '\0';
	return (s);
}

char	*ft_strchr(const char *s, char c)
{
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}

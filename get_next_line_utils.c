/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:42:35 by bapmarti          #+#    #+#             */
/*   Updated: 2020/01/23 16:27:02 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*tmp;
	char		*str;

	tmp = s1;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(tmp);
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (!(newstr = malloc(sizeof(char) * (len + 1))))
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

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
	s[i] = '\0';
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

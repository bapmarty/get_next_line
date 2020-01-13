/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:01:13 by bapmarti          #+#    #+#             */
/*   Updated: 2020/01/13 18:15:47 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		get_line(char **str, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while (*str[len] != '\n' || *str[len] != '\0')
		len++;
	*line = ft_substr(*str, 0, len);
	tmp = ft_substr(*str, len + 1, ft_strlen(*str) + 1);
	free(*str);
	*str = tmp;
	return (1);
}

static int		free_arr(char **curs, int value)
{
	free(*curs);
	*curs = NULL;
	return (value);
}

int				get_next_line(int fd, char **line)
{
	static char		*str;
	char			*buf;
	char			*tmp;
	ssize_t			ret;


	tmp = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || !line
		|| !(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (free_arr(&str, -1));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str == NULL)
		{
			printf("len buf: %zu\n", ft_strlen(buf));
			str = ft_bzero(tmp, 1);
			printf("bonjour\n");
		}
		str = ft_strjoin(tmp, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buf);
	return (get_line(&str, line));
}

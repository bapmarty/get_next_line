/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:01:13 by bapmarti          #+#    #+#             */
/*   Updated: 2020/01/13 19:17:57 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		find_next_line(char *str)
{
	int pos;

	pos = 0;
	while (str[pos] != '\0' && str[pos] != '\n')
		pos++;
	return (pos);
}

static int		get_line(char **str, char **line)
{
	char	*tmp;

	*line = ft_substr(*str, 0, find_next_line(*str));
	tmp = ft_substr(*str, find_next_line(*str) + 1, ft_strlen(*str) + 1);
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


	if (BUFFER_SIZE < 1 || fd < 0 || !line
		|| !(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (free_arr(&str, -1));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strnew(1);
		str = ft_strjoin(str, buf);
		tmp = str;
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (get_line(&str, line));
}

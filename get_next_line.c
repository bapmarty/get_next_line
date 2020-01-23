/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:01:13 by bapmarti          #+#    #+#             */
/*   Updated: 2020/01/23 16:26:25 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		find_next_line(char *str)
{
	int pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1);
}

static int		get_line(char **str, char **line)
{
	char	*tmp;
	int		pos;

	if ((pos = find_next_line(*str)) == -1)
	{
		*line = ft_substr(*str, 0, pos);
		return (0);
	}
	*line = ft_substr(*str, 0, pos);
	tmp = ft_substr(*str, pos + 1, ft_strlen(*str) - pos);
	free(*str);
	*str = tmp;
	return (1);
}

static int		free_arr(char **str, int value)
{
	free(*str);
	*str = NULL;
	return (value);
}

int				get_next_line(int fd, char **line)
{
	static char		*str;
	char			*buf;
	int				ret;

	ret = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || !line
		|| !(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (free_arr(&str, -1));
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strnew(1);
		str = ft_strjoin_free(str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buf);
	if (ret < 0)
		return (-1);
	ret = get_line(&str, line);
	if (ret == 0)
		free(str);
	return (ret);
}

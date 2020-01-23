/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:59:31 by bapmarti          #+#    #+#             */
/*   Updated: 2020/01/23 16:27:29 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);

char	*ft_strnew(size_t size);
char	*ft_strjoin_free(char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, char c);

#endif

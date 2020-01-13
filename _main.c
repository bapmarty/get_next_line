/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:11:07 by atrouill          #+#    #+#             */
/*   Updated: 2020/01/13 20:18:06 by bapmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>  // include open
#include <sys/stat.h>   // include open (à supprimer si on ne fait pas d'appel à open dans le fichier)
#include <fcntl.h>      // include open

int             main(int argc, char *argv[])
{
        char    *str;
        int     fd;
        int     ret = 1;

        str = NULL;
        errno = 0;
        if (argc == 1)
        {
                fd = STDIN_FILENO;
        }
        else if (argc == 2)
        {
                if ((fd = open(argv[1], O_RDONLY)) == -1)
                {
                        fprintf(stderr, "Error : Couldn't open \"%s\" (%s).\n", argv[1], strerror(errno));
                        return (1);
                }
        }
        else
        {
                fprintf(stderr, "Usage :\na.out --> read the satndard input\na.out <filename> -->Read the file\n");
                return (1);
        }
        while (ret > 0)
        {
                ret = get_next_line(fd, &str);
                printf("Return : %d\nRead : %s\n", ret, str);
	        	free(str);
				str = NULL;
        }
        return (0);
}

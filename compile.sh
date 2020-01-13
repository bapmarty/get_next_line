#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapmarti <bapmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 10:09:14 by bapmarti          #+#    #+#              #
#    Updated: 2019/11/27 10:09:14 by bapmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#gcc -Wall -Wextra -Werror -g3 -fsanitize=address -D BUFFER_SIZE=12 _main.c get_next_line.c get_next_line_utils.c 
gcc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=12 _main.c get_next_line.c get_next_line_utils.c 

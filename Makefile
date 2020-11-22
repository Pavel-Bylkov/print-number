# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cclock <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/05 16:01:11 by cclock            #+#    #+#              #
#    Updated: 2020/09/06 23:17:02 by whector          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = rush_check.c rush_dict.c rush_main.c rush_print_nbr.c\
	   rush_str_copy.c rush_strs.c rush_tree.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

NAME = rush-02

.c.o:
			gcc ${FLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

.PHONY:		all clean fclean


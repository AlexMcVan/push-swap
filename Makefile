# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 17:40:07 by amarie-c          #+#    #+#              #
#    Updated: 2022/01/11 20:02:39 by amarie-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

SRC		= main.c push.c operations.c parsing.c sorting.c libft.c ft_itoa.c gain_function.c

CFLAGS	= -Wall -Wextra -Werror -g3

SANITIZE	= -fsanitize=address

HEADER	=	push_swap.h

OBJS	= ${SRC:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${HEADER} 
			${CC} ${CFLAGS}  -o ${NAME} ${OBJS}
# ${SANITIZE}
.c.o:	${CC} ${CFLAGS} -c $< o ${<:.c=.o}

clean:	
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

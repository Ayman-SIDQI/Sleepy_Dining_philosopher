# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:19:18 by asidqi            #+#    #+#              #
#    Updated: 2023/05/07 19:19:29 by asidqi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

CC=cc

FLAGS=-Wall -Wextra -Werror -g -fsanitize=thread

SRC= errors.c \
	func.c \
	philo.c \
	utils.c \
	routine.c \
	error_function.c


OBJ=${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	@${CC} ${FLAGS} $^ -o $@

%.o : %.c
	@${CC} ${FLAGS} -c $< -o $@

clean :
	@rm -f ${OBJ}

fclean :
	@rm -rf ${OBJ} ${NAME}

re : clean all

.PHONY:all fclean clean re
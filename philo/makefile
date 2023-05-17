NAME=philo

CC=cc

FLAGS=-Wall -Wextra -Werror #-g -fsanitize=thread

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
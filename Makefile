CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRCS =		main.c \
		push_swap.c \
		operations.c \
		operation_handler.c

OBJS =		${SRCS:.c=.o}
NAME =		push_swap

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -L./libft -lft -o ${NAME} 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

# TESTS
LEAKS =	valgrind -q --leak-check=full --track-origins=yes

test: all
	./push_swap 2 1 3 6 5 8

ulibft:
	cd ../libft/ && make bonus
	cp ../libft/libft.h ./libft/
	cp ../libft/libft.a ./libft/

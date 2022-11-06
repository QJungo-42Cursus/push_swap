NAME =		push_swap

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRCS =		main.c \
			push_swap.c \
			operations.c \
			operation_handler.c \
			utils.c \
			bubble_sort.c

OBJS =		${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@make all -C libft
	${CC} ${CFLAGS} ${OBJS} -L./libft -lft -o ${NAME} 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

# TESTS
LEAKS =	valgrind -q --leak-check=full --track-origins=yes


#ARGS = 2 1 3 90 "-8" 40 6

ARGS = 1 2 3 4 6 -80 -90 -81 5 0 -50 -51 10000 500

leaks: all
ifeq ($(shell uname), Linux)
	$(LEAKS) ./push_swap $(ARGS)
else 
	#leaks mac
endif		

test: all
ifeq ($(shell uname), Linux)
	#$(LEAKS) ./push_swap 
	./push_swap $(ARGS) | ./checker_linux $(ARGS)
else 
	 ./push_swap $(ARGS) | ./checker_linux $(ARGS)
endif		

NAME =		push_swap

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRCS =		main.c \
			push_swap.c \
			operations.c \
			operation_handler.c \
			log.c \
			partition.c \
			new.c \
			mov.c \
			get.c \
			bubble_sort.c

OBJS =		${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@make all -C libft
	${CC} ${CFLAGS} ${OBJS} -L./libft -lft -o ${NAME} 

clean:
	#@make clean -C libft
	${RM} ${OBJS}

fclean: clean
	#@make fclean -C libft
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

qt: all
	clear
	./push_swap 1 80 5 4 61 -60 10

test: all
ifeq ($(shell uname), Linux)
	#$(LEAKS) ./push_swap 
	./push_swap $(ARGS) | ./checker_linux $(ARGS)
else 
	 ./push_swap $(ARGS) | ./checker_linux $(ARGS)
endif		

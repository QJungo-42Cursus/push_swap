NAME =		push_swap
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f

SRCS =		main.c \
			push_swap.c \
			first_tri.c \
			op/operations.c \
			op/operation_handler.c \
			op/new.c \
			op/mov.c \
			op/get.c \
			sorting_algos/bubble_sort.c \
			sorting_algos/stupid_sort.c \
			tests/log.c \

OBJS =		$(SRCS:.c=.o)

ifeq ($(shell uname), Linux)
LEAKS =	valgrind -q --leak-check=full --track-origins=yes
else 
LEAKS = leaks -atExit -- 
endif		

all: $(NAME)

u_libft:
	rm -rf ./libft
	cp -r ../libft .
	rm -rf ./libft/.git

$(NAME): $(OBJS)
	@make all -C libft
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME) 

clean:
	#@make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	#@make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


###  TESTS ALL  ###
ARGS = 1 2 655 0 -80 700 701
ARGS2 = 1 2 655 0 -80 700 701 -59 -95 -34

t: all
	./push_swap $(ARGS)
	./push_swap $(ARGS2)

check: all
	./push_swap $(ARGS2) | ./checker_linux $(ARGS2)


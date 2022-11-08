NAME =		push_swap

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRCS =		main.c \
			push_swap.c \
			operations.c \
			operation_handler.c \
			log.c \
			new.c \
			mov.c \
			get.c \
			bubble_sort.c \
			quicksort/partition.c \
			quicksort/quicksort.c \
			quicksort/back_to_parent.c

SRC_TEST = main_test.c

SRCS_TEST =	$(addprefix tests/,	$(SRC_TEST))
OBJS_TEST =	$(SRCS_TEST:.c=.o)

OBJS =		$(SRCS:.c=.o)

ifeq ($(shell uname), Linux)
LEAKS =	valgrind -q --leak-check=full --track-origins=yes
else 
LEAKS = leaks
endif		


all: $(NAME)

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
ARGS = 1 2 3 4 6 -80 -90 -81 5 0 -50 -51 10000 500

leaks: all
	$(LEAKS) ./push_swap $(ARGS)

qt: re
	clear
	./push_swap 1 80 5 4 61 -60 10

ft: all
ifeq ($(shell uname), Linux)
	./push_swap $(ARGS) | ./checker_linux $(ARGS)
else 
	 #./push_swap $(ARGS) | ./checker_XXX $(ARGS)
endif		

###  UNIT TESTS  ###
# main
main_test: clean_test
	clear
	@make all -C libft
	@$(CC) $(CFLAGS) -D MAIN_TEST get.c log.c $(SRCS_TEST) -L./libft -lft -o test.out
	make main_test -C tests

# back to parent
btp_test: clean_test
clean_test:
	$(RM) $(OBJS_TEST) test.out




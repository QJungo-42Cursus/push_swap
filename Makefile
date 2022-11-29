NAME =		push_swap
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f

S =			push_swap.c \
			operations.c \
			operation_handler.c \
			log.c \
			new.c \
			mov.c \
			get.c \
			quicksort/quicksort.c \
			quicksort/partition.c \
			quicksort/loop.c \
			quicksort/back_to_parent.c

SRCS =		main.c $(S)

SRC_TEST =	main_test.c \
			mov_test.c \
			btp_test.c \
			utils.c 

SRCS_TEST =	$(addprefix tests/,	$(SRC_TEST))
OBJS_TEST =	$(SRCS_TEST:.c=.o)

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

leaks: all
	$(LEAKS) ./push_swap $(ARGS)

qt: re
	clear
	./push_swap $(ARGS)

ft: all
ifeq ($(shell uname), Linux)
	./push_swap $(ARGS) | ./checker_linux $(ARGS)
else 
	 #./push_swap $(ARGS) | ./checker_XXX $(ARGS)
endif		

###  UNIT TESTS  ###
TESTS = ./test.out

# clean
tclean: fclean
	$(RM) $(OBJS_TEST) test.out

t:
	clear
	@make all -C libft
	@$(CC) $(CFLAGS) radix_sort/radix_sort.c -L./libft -lft -o test.out
	./test.out

# main
main_test: tclean 
	clear
	@make all -C libft
	@$(CC) $(CFLAGS) -D MAIN_TEST get.c log.c $(SRCS_TEST) -L./libft -lft -o test.out
	make main_test -C tests

# back to parent
btp_test: tclean fclean
	@$(CC) $(CFLAGS) -D BTP_TEST $(S) $(SRCS_TEST) -L./libft -lft -o test.out
	@clear
	$(TESTS)

# mov
mov_test: tclean
	clear
	@make all -C libft
	@$(CC) -D MOV_TEST operation_handler.c operations.c mov.c get.c log.c $(SRCS_TEST) -L./libft -lft -o test.out
	$(TESTS)

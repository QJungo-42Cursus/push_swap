NAME =     		libft.a
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
RM =			rm -f

SRCS_STR =		ft_strmapi.c \
				ft_striteri.c \
				ft_strnstr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_split.c \
				char_to_str.c \
				strlen_until.c \
				strrev.c

SRCS_NB = 		ft_itoa.c \
				ft_atoi.c \
				itoa_base.c \
				utoa.c

SRCS_CHAR = 	ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				is_in_charset.c

SRCS_LST = 		ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

SRCS_PRT = 		ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_printf/ft_printf.c \
				ft_printf/conversions/conversions.c \
				ft_printf/conversions/character.c \
				ft_printf/conversions/hexa.c \
				ft_printf/conversions/pointer.c \
				ft_printf/writer/writer.c \
				ft_printf/utils/free_join.c \
				ft_printf/utils/index_words.c

SRCS_MEM =		ft_calloc.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memcmp.c \
				ft_memchr.c \
				ft_memset.c \
				ft_memmove.c

SRCS_MATH = 	geometrie/line.c \
				geometrie/translation.c \
				geometrie/map_op.c \
				geometrie/conversions.c \
				matrix/operations.c \
				matrix/conversions.c \
				matrix/new.c \
				vec/new.c \
				vec/copy.c \
				vec/conversions.c \
				vec/assert.c \
				new_.c

SRCS_MLX = 		line.c \
				line.c \
				draw_line.c \
				pixel_to_image.c

SRCS = 			$(addprefix char/,	$(SRCS_CHAR)) \
				$(addprefix str/,	$(SRCS_STR)) \
				$(addprefix lst/,	$(SRCS_LST)) \
				$(addprefix mem/,	$(SRCS_MEM)) \
				$(addprefix nb/,	$(SRCS_NB)) \
				$(addprefix prt/,	$(SRCS_PRT)) \
				$(addprefix math/,	$(SRCS_MATH)) \
				$(addprefix mlx/,	$(SRCS_MLX)) \
				get_next_line.c

OBJS =			$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

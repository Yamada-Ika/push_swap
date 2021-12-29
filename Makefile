CC			:= gcc
CFLAGS		:= #-Wall -Wextra -Werror

# libft
LIBFT_DIR	:= libft
LIBFT_A		:= libft.a
LIBFT_A		:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

# push_swap
NAME 		:= push_swap
SRCS		:= \
arg_utils.c              order_1.c	\
array_utils.c            order_2.c	\
bilist_utils_1.c         order_helper.c	\
bilist_utils_2.c         push_swap.c	\
bilist_utils_3.c         sort_small_stack_utils.c	\
ft_pa_half.c      stack_utils.c	\
ft_pb_half.c
OBJS		:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT_A)

$(LIBFT_A): empty
	make -C $(LIBFT_DIR)

empty:

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft empty

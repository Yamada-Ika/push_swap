CC			:= gcc
CFLAGS		:= #-Wall -Wextra -Werror

# libft
LIBFT_DIR	:= libft
LIBFT_A		:= libft.a
LIBFT_A		:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

# push_swap
NAME 				:= push_swap
PUSH_SWAP_DIR		:= push_swap_files
PUSH_SWAP_SRCS		:= \
arg_utils.c              order_1.c	\
array_utils.c            order_2.c	\
bilist_utils_1.c         order_helper.c	\
bilist_utils_2.c         push_swap.c	\
bilist_utils_3.c         sort_small_stack_utils.c	\
ft_pa_half.c      stack_utils.c	\
ft_pb_half.c
PUSH_SWAP_SRCS		:= $(addprefix $(PUSH_SWAP_DIR)/, $(PUSH_SWAP_SRCS))

# checker
CHECKER_NAME	:= checker
CHECKER_DIR		:= checker_files
CHECKER_SRCS	:= \
bilist_utils.c        get_next_line_utils.c	\
create_stack.c        main.c				\
get_next_line.c       order.c
CHECKER_SRCS	:= $(addprefix $(CHECKER_DIR)/, $(CHECKER_SRCS))

all: $(NAME)

$(NAME): $(LIBFT_A) $(PUSH_SWAP_SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_SRCS) $(LIBFT_A)

$(LIBFT_A): empty
	make -C $(LIBFT_DIR)

empty:

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(LIBFT_A) $(CHECKER_SRCS)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_SRCS) $(LIBFT_A)

clean:
	rm -rf $(NAME) $(CHECKER_NAME)

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft empty

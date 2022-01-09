CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror

# libft
LIBFT_DIR		:= libft
LIBFT_A			:= libft.a
LIBFT_A			:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

# push_swap
NAME 			:= push_swap
PUSH_SWAP_DIR	:= push_swap_files
PUSH_SWAP_SRCS	:= $(wildcard $(PUSH_SWAP_DIR)/*.c)
PUSH_SWAP_OBJS	:= $(PUSH_SWAP_SRCS:%.c=%.o)

# checker
CHECKER_NAME	:= checker
CHECKER_DIR		:= checker_files
CHECKER_SRCS	:= $(wildcard $(CHECKER_DIR)/*.c)
CHECKER_OBJS	:= $(CHECKER_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(LIBFT_A)

$(LIBFT_A): empty
	make -C $(LIBFT_DIR)

empty:

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(LIBFT_A) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJS) $(LIBFT_A)

clean:
	rm -rf $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -rf $(NAME) $(CHECKER_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft empty

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

# libft
LIBFT_DIR	:= libft
LIBFT_A		:= libft.a
LIBFT_A		:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

# push_swap
NAME 				:= push_swap
PUSH_SWAP_DIR		:= push_swap_files
PUSH_SWAP_SRCS		:= $(wildcard $(PUSH_SWAP_DIR)/*.c)

# checker
CHECKER_NAME	:= checker
CHECKER_DIR		:= checker_files
CHECKER_SRCS	:= $(wildcard $(CHECKER_DIR)/*.c)

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

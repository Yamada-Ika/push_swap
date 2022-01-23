CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror

# libft
LIBFT_DIR		:= libft
LIBFT_A			:= libft.a
LIBFT_A			:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

# push_swap
NAME 			:= push_swap
PUSH_SWAP_DIR	:= push_swap_files
PUSH_SWAP_SRCS	:= \
ft_arry_compress.c       main.c                   sort_small_stack_utils.c	\
ft_pa_half.c             order_1.c                stack_utils.c			\
ft_pb_half.c             order_2.c
PUSH_SWAP_OBJS	:= $(PUSH_SWAP_SRCS:%.c=%.o)
PUSH_SWAP_SRCS	:= $(addprefix $(PUSH_SWAP_DIR)/, $(PUSH_SWAP_SRCS))
PUSH_SWAP_OBJS	:= $(addprefix $(PUSH_SWAP_DIR)/out/, $(PUSH_SWAP_OBJS))

# checker
CHECKER_NAME	:= checker
CHECKER_DIR		:= checker_files
CHECKER_SRCS	:= \
ft_get_operation.c    main.c                op_3.c	\
get_next_line.c       op_1.c						\
get_next_line_utils.c op_2.c
CHECKER_OBJS	:= $(CHECKER_SRCS:%.c=%.o)
CHECKER_SRCS	:= $(addprefix $(CHECKER_DIR)/, $(CHECKER_SRCS))
CHECKER_OBJS	:= $(addprefix $(CHECKER_DIR)/out/, $(CHECKER_OBJS))

# utils
UTILS_SRC	:= \
arry_utils.c           ft_error.c             ft_new_stack.c	\
bilist_utils.c         ft_get_arry_from_arg.c op_utils.c		\
ft_delete_stack.c      ft_is_wrong_arry.c     stack_utils.c
UTILS_OBJS	:= $(UTILS_SRC:%.c=%.o)
UTILS_SRCS	:= $(addprefix utils/, $(UTILS_SRC))
UTILS_OBJS	:= $(addprefix utils/out/, $(UTILS_OBJS))

all: $(NAME)

$(NAME): $(LIBFT_A) $(PUSH_SWAP_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(UTILS_OBJS) $(LIBFT_A)

$(LIBFT_A): empty
	make -C $(LIBFT_DIR)

empty:

$(PUSH_SWAP_DIR)/out/%.o: $(PUSH_SWAP_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^ -Ipush_swap_files/include -Ilibft -Iutils/include

utils/out/%.o: utils/%.c
	$(CC) $(CFLAGS) -o $@ -c $^ -Ilibft -Iutils/include
	# $(CC) $(CFLAGS) -o $@ -c $^ -Ilibft -Iutils/include -Ipush_swap_files/include

$(CHECKER_DIR)/out/%.o: $(CHECKER_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^ -Ichecker_files/include -Ilibft -Iutils/include

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(LIBFT_A) $(CHECKER_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJS) $(UTILS_OBJS) $(LIBFT_A)

clean:
	rm -rf $(PUSH_SWAP_OBJS) $(CHECKER_OBJS) $(UTILS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME) $(CHECKER_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re empty

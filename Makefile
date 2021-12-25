CC			:= gcc
CFLAGS		:= #-g -fsanitize=address #-Wall -Wextra -Werror

NAME 		:= push_swap
SRCS		:= \
arg_utils.c      bilist_utils_3.c push_swap.c	\
array_utils.c    order_1.c        sort_utils.c	\
bilist_utils_1.c order_2.c        stack_utils.c	\
bilist_utils_2.c order_helper.c
OBJS		:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft empty

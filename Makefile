CC			:= gcc
CFLAGS		:= -g -fsanitize=address #-Wall -Wextra -Werror

NAME 		:= push_swap
SRCS		:= push_swap.c ft_bilist.c
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

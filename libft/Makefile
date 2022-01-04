CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -c
NAME 		:= libft.a
HEADERFILE	:= libft.h
SRCS		:= \
ft_atoi.c         ft_lltoa_base.c   ft_memmove.c      ft_strcmp.c       ft_strstr.c		\
ft_atoll.c        ft_lstadd_back.c  ft_memset.c       ft_strdup.c       ft_strtoll.c	\
ft_bzero.c        ft_lstadd_front.c ft_putchar.c      ft_striteri.c     ft_strtrim.c	\
ft_calloc.c       ft_lstclear.c     ft_putchar_fd.c   ft_strjoin.c      ft_substr.c		\
ft_free_s.c       ft_lstdelone.c    ft_putendl_fd.c   ft_strlcat.c      ft_tolower.c	\
ft_isalnum.c      ft_lstiter.c      ft_putnbr.c       ft_strlcpy.c      ft_toupper.c	\
ft_isalpha.c      ft_lstlast.c      ft_putnbr_base.c  ft_strlen.c       ft_uitoa.c		\
ft_isascii.c      ft_lstmap.c       ft_putnbr_fd.c    ft_strlen_s.c     ft_uitoa_base.c	\
ft_isdigit.c      ft_lstnew.c       ft_putstr.c       ft_strmapi.c      ft_ultoa.c		\
ft_isprint.c      ft_lstsize.c      ft_putstr_fd.c    ft_strncmp.c      ft_ultoa_base.c	\
ft_itoa.c         ft_memchr.c       ft_putuinbr.c     ft_strnstr.c						\
ft_itoa_base.c    ft_memcmp.c       ft_split.c        ft_strrchr.c						\
ft_lltoa.c        ft_memcpy.c       ft_strchr.c       ft_strrev.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HEADERFILE)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

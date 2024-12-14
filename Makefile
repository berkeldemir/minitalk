NAME = minitalk.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS=.c:.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
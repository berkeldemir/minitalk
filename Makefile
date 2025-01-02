CC = cc
CFLAGS = -Wall -Wextra -Werror

all: client.c server.c
	$(CC) $(CFLAGS) client.c ft_printf.c -o client
	$(CC) $(CFLAGS) server.c ft_printf.c -o server

clean:
	rm client server 

fclean: clean

re: fclean all

.PHONY: all clean fclean re
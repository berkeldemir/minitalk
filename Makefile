# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 13:35:32 by beldemir          #+#    #+#              #
#    Updated: 2025/01/02 13:35:33 by beldemir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: client.c server.c
	$(CC) $(CFLAGS) client.c ft_printf.c -o client
	$(CC) $(CFLAGS) server.c ft_printf.c -o server

bonus: client_bonus.c server_bonus.c
	$(CC) $(CFLAGS) client_bonus.c ft_printf.c -o client
	$(CC) $(CFLAGS) server_bonus.c ft_printf.c -o server

clean:
	rm client server 

fclean: clean

re: fclean all

.PHONY: all clean fclean re
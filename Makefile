# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 14:08:05 by jbyeon            #+#    #+#              #
#    Updated: 2021/08/26 18:57:00 by jbyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wextra -Wall -Werror
RM			= rm -f

LIBFT		= libft
LIBFT_LIB	= libft/libft.a

SERVER		= server
SERVER_BONUS	= server_bonus
CLIENT		= client
CLIENT_BONUS	= client_bonus

all : libfta $(SERVER) $(CLIENT)

bonus : libfta $(SERVER_BONUS) $(CLIENT_BONUS)

libfta :
	make all -C $(LIBFT)

$(SERVER) : 
	$(CC) $(CFLAGS) server.c $(LIBFT_LIB) -o $(SERVER)

$(CLIENT) : 
	$(CC) $(CFLAGS) client.c $(LIBFT_LIB) -o $(CLIENT)

$(SERVER_BONUS) :
	$(CC) $(CFLAGS) $(SERVER_BONUS).c $(LIBFT_LIB) -o $(SERVER_BONUS)

$(CLIENT_BONUS) :
	$(CC) $(CFLAGS) $(CLIENT_BONUS).c $(LIBFT_LIB) -o $(CLIENT_BONUS)

fclean : clean
	make fclean -C $(LIBFT)
	$(RM) *.o $(SERVER) $(CLIENT) libft.a $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
	make clean -C $(LIBFT)
	$(RM) *.o

re : fclean all

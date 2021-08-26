# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 14:08:05 by jbyeon            #+#    #+#              #
#    Updated: 2021/08/26 15:16:59 by jbyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wextra -Wall -Werror
RM			= rm -f

LIBFT		= libft
LIBFT_LIB	= libft/libft.a

SERVER		= server
CLIENT		= client

all : libfta $(SERVER) $(CLIENT)

libfta :
	make all -C $(LIBFT)

$(SERVER) : 
	$(CC) $(CFLAGS) server.c $(LIBFT_LIB) -o $(SERVER)

$(CLIENT) : 
	$(CC) $(CFLAGS) client.c $(LIBFT_LIB) -o $(CLIENT)

fclean : clean
	make fclean -C $(LIBFT)
	$(RM) *.o $(SERVER) $(CLIENT) libft.a

clean :
	make clean -C $(LIBFT)
	$(RM) *.o

re : fclean all

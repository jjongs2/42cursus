# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 20:42:46 by kijsong           #+#    #+#              #
#    Updated: 2022/08/25 14:39:55 by kijsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	=	server
CLIENT	=	client

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

UTIL	=	ft_printf.c ft_utils_number.c ft_utils_signal.c ft_utils_string.c
SRC_S	=	server.c $(UTIL)
SRC_C	=	client.c $(UTIL)
SRC_S_B	=	server_bonus.c $(UTIL)
SRC_C_B	=	client_bonus.c $(UTIL)

OBJ_S	=	$(SRC_S:.c=.o)
OBJ_C	=	$(SRC_C:.c=.o)
OBJ_S_B	=	$(SRC_S_B:.c=.o)
OBJ_C_B	=	$(SRC_C_B:.c=.o)

ifdef FLAG_B
	OBJ_S = $(OBJ_S_B)
	OBJ_C = $(OBJ_C_B)
endif

all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(SERVER): $(OBJ_S)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT): $(OBJ_C)
	$(CC) $(CFLAGS) -o $@ $^

bonus:
	@make FLAG_B=1

clean:
	$(RM) $(OBJ_S) $(OBJ_C) $(OBJ_S_B) $(OBJ_C_B)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re

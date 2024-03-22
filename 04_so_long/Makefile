# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 13:38:27 by kijsong           #+#    #+#              #
#    Updated: 2022/08/13 23:58:55 by kijsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
MLX		=	-Lmlx -lmlx
F/W		=	-framework OpenGL -framework AppKit
RM		=	rm -f

SRC_DIR	=	./src/
SRC_B_DIR =	./src_bonus/
MLX_DIR	=	./mlx/

SRC		=	main.c ft_verify.c ft_draw.c ft_key.c \
			ft_utils_string.c ft_utils_malloc.c get_next_line.c

SRC_B	=	main_bonus.c ft_verify_bonus.c ft_draw_bonus.c \
			ft_key_bonus.c ft_move_bonus.c ft_utils_string_bonus.c \
			ft_utils_malloc_bonus.c get_next_line_bonus.c

SRCS	=	$(addprefix $(SRC_DIR), $(SRC))
SRCS_B	=	$(addprefix $(SRC_B_DIR), $(SRC_B))

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

ifdef FLAG_B
	OBJS = $(OBJS_B)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX) $(F/W) -o $@ $^

bonus:
	@make FLAG_B=1

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re

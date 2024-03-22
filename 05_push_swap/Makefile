# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 13:38:27 by kijsong           #+#    #+#              #
#    Updated: 2022/08/21 18:57:08 by kijsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME_B	=	checker

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

SRC		=	main.c ft_verify.c ft_scale.c ft_sort.c ft_optimize.c \
			ft_operate.c ft_sort_2_3.c ft_split.c ft_utils_free.c \
			ft_utils_list.c ft_utils_malloc.c ft_utils_oper_pair.c \
			ft_utils_oper.c ft_utils_str.c ft_utils_opt.c

SRC_B	=	checker.c ft_verify.c ft_scale.c ft_split.c \
			ft_utils_free.c	ft_utils_list.c ft_utils_malloc.c \
			ft_utils_oper.c ft_utils_str.c get_next_line.c

SRCS	=	$(addprefix $(SRC_DIR), $(SRC))
SRCS_B	=	$(addprefix $(SRC_B_DIR), $(SRC_B))

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

ifdef FLAG_B
	NAME = $(NAME_B)
	OBJS = $(OBJS_B)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 08:04:30 by tanukool          #+#    #+#              #
#    Updated: 2022/08/11 08:10:07 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:%.c=%.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

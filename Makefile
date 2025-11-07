# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysahnoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 18:06:00 by ysahnoun          #+#    #+#              #
#    Updated: 2025/11/05 18:12:13 by ysahnoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC	= ft_printf.c ft_printf2.c

OBJS	= $(SRC:.c=.o)

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

AR          = ar rcs
RM          = rm -f

# --- Rules ---

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

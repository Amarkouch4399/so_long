# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 17:37:50 by ouamarko          #+#    #+#              #
#    Updated: 2025/05/17 16:29:59 by ouamarko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

SRC	= ft_printf.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_putchar.c \
	  ft_hexa_upper.c \
	  ft_putchar_pointer.c \
	  ft_putnbr_hexa.c \
	  ft_putnbr_unsigned.c


OBJS	= ${SRC:.c=.o}

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

AR	= ar rc

all: ${NAME}
	@echo "Done ✅"

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re


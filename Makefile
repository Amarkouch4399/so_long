# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 20:02:57 by ouamarko          #+#    #+#              #
#    Updated: 2025/11/04 19:24:25 by ouamarko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC	= so_long.c \
	  utils/ft_strstr.c \
	  utils/ft_length.c \
	  utils/ft_split.c \
	  utils/ft_free_map.c \
	  utils/ft_trim_newline.c \
	  parsing/ft_validate_format.c \
	  $(GNL_DIR)/get_next_line.c \
	  $(GNL_DIR)/get_next_line_utils.c \

OBJS	= ${SRC:.c=.o}

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g -Iincludes -Ift_printf

MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lm -lmlx -lXext -lX11
GNL_DIR = ./gnl
INC_DIR = ./includes
PRINTF_DIR = ./ft_printf

# =============================================

all: ${NAME}

${MLX_PATH}/libmlx.a:
	@make -C ${MLX_PATH}

${NAME}: ${OBJS} ${MLX_PATH}/libmlx.a
	@make -C ${PRINTF_DIR}
	${CC} ${CFLAGS} ${OBJS} -L${MLX_PATH} -L${PRINTF_DIR} -lftprintf -lmlx -lXext -lX11 -lm -o ${NAME}
	@echo "✅ Compil done"

%.o: %.c
	${CC} ${CFLAGS} -I$(MLX_PATH) -c $< -o $@

clean:
	rm -f ${OBJS}
	@make clean -C ${PRINTF_DIR}
	@echo "🧹 clean done"

fclean: clean
	rm -f ${NAME}
	@make fclean -C ${PRINTF_DIR}
	@echo "full clean done"

re: fclean all

.PHONY: all clean fclean re

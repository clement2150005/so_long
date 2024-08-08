# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 16:19:44 by ccolin            #+#    #+#              #
#    Updated: 2024/08/08 16:19:51 by ccolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iinclude

MLX_DIR	= minilibx_opengl_20191021
MLX_LIB	= $(MLX_DIR)/libmlx.a
MLX_INC	= -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/includes

SRCS	= $(wildcard *.c)

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) $(LIBFT_INC) -c $< -o $@

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re

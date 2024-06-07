# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 23:45:15 by baguiar-          #+#    #+#              #
#    Updated: 2024/05/21 23:45:15 by baguiar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT	= ./libft/libft.a
MLX_LIB = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a
INC		= include/
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -I
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

SO_LONG_DIR	=		$(SRC_DIR)error.c	\
					$(SRC_DIR)fnd_a_b.c	\
					$(SRC_DIR)fnd_b_a.c \
					$(SRC_DIR)init_stacks.c	\
					$(SRC_DIR)push_swap.c \
					$(SRC_DIR)split.c	\
					$(SRC_DIR)utils.c \

SRCS = $(SO_LONG_DIR)

OBJ	:= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
	@make all

$(LIBFT):
	@make -C ./libft

$(MLX):
	@make -C ./minilibx-linux

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft
	@make clean -C ./minilibx-linux

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(MLX)

re: fclean all

.PHONY: all clean start fclean re
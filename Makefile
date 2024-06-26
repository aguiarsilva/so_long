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
INC		= includes/
SRC_DIR = src/
OBJ_DIR = obj/
CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -I
MLX_FLAGS = -L$(MLX_LIB) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lXrandr -lXinerama -lXcursor -lXrender

SO_LONG_DIR	=		$(SRC_DIR)events.c	\
					$(SRC_DIR)map_control.c	\
					$(SRC_DIR)map_size.c \
					$(SRC_DIR)moves.c	\
					$(SRC_DIR)put_map.c \
					$(SRC_DIR)parse_map.c	\
					$(SRC_DIR)so_long.c \
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
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

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
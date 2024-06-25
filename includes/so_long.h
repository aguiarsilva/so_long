/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:11:12 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/04 15:11:12 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void    *img;
	int     height;
	int     width;
}   t_img;

typedef struct s_game
{
	void    *mlx;
	void    *window;
	int		width;
	int		height;
	int		collectibles;
	int		exit_E;
	int		begin;
	int		move;
	char	*str;
	t_img   player;
	t_img   exit;
	t_img   wall;
	t_img   collectible;
	t_img   floor;
}   t_game;

void    exit_error(char *error_msg);
int     open_map(int argc, char **argv);
char	*map_read(int fd);
int     size_col(t_game *game);
int     size_lin(t_game *game);
int     close_game(t_game *game);
void    event_receiver(t_game *game);
void    exit_game(t_game *game, char *msg);
void	map_parse(t_game *game);
int     sprite_move(int keycode, t_game *game);
int     len_array(char **arr);
void    free_game_array(int arr_len, char **arr, t_game *game, int err);
int     put_map(t_game *game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:26:16 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/14 14:26:16 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	fd = open_map(argc, argv);
	game.str = map_read(fd);
	map_parse(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);
	game.width = size_col(&game) * 64;
	game.height = size_lin(&game) * 64;
	game.window = mlx_new_window(game.mlx, game.width, game.height, argv[0]);
	if (game.window == NULL)
	{
		free(game.window);
		return (1);
	}
	game.move = 0;
	event_receiver(&game);
	free(game.str);
	return (0);
}

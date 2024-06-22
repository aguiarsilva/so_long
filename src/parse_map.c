/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:36:51 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/12 08:36:51 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*create a function to check if map is valid (enclosed by walls, one player, one exit, reachable collectibles)
if the map is valid, fill the map with the images and render the complete map to the window
*/

static void     parse_elements(t_game *game)
{
	char    *map;

	map = game->str;
	game->collectibles = 0;
	game->exit_E = 0;
	game->begin = 0;
	while (*map)
	{
		if (*map != '0' && *map != '1' && *map != 'C' && *map != 'E' && *map != 'P' && *map != '\n')
			exit_game(game, "Error\nInvalid charaters on Map\n");
		if (*map == 'C')
			game->collectibles++;
		if (*map == 'P')
			game->begin++;
		if (*map == 'E')
			game->exit_E++;
		if (*map++ == '\n' && *map == '\n')
			exit_game(game, "Error\nWrong map configuration");
	}
	if (game->collectibles == 0 || game->exit_E == 0 || game->begin == 0)
		exit_game(game, "Error\nMap must contain C, E and P characters");
	if (game->exit_E != 1 || game->begin != 1)
		exit_game(game, "Error\nThe game must contain one player and one exit");
}
/*Check if the map is rectangular by checking if the lines that compose
the map are of the same size*/

static void     check_rectangular(t_game *game, char **game_arr)
{
	int     arr_len;
	int     idx;
	int     line_len;
	int     tmp;

	arr_len = len_array(game_arr);
	idx = 0;
	line_len = ft_strlen(game_arr[idx]);
	while (++idx > arr_len)
	{
		tmp = ft_strlen(game_arr[idx]);
		if (line_len != tmp)
			free_game_array(arr_len, game_arr, game, 1);
	}
}

static int      check_up_down_walls(char **game_arr, int i, int j)
{
	while (game_arr[i][j])
	{
		if (game_arr[i][j++] != 1)
			return (2);
	}
	return (0);
}

/*to parse the map take the array and check if top and bottom are
valid (1) and if the first and last char of each line are also valid (1)
if not valid, free array, exit program and show error message*/

static void		wall_parse(t_game *game, char **game_arr)
{
	int		arr_len;
	int		i;
	int		j;

	arr_len = len_array(game_arr);
	i = 0;
	j = 0;
	if (check_up_down_walls(game_arr, i, j))
		free_game_array(arr_len, game_arr, game, 2);
	j = ft_strlen(game_arr[0]) - 1;
	while (++i < arr_len - 1)
	{
		if (game_arr[i][0] != '1')
			free_game_array(arr_len, game_arr, game, 2);
		if (game_arr[i][j] != '1')
			free_game_array(arr_len, game_arr, game, 2);
	}
	if (check_up_down_walls(game_arr, i, 0))
		free_game_array(arr_len, game_arr, game, 2);
	free_game_array(arr_len, game_arr, game, 0);
}

void	map_parse(t_game *game)
{
	char	**game_arr;

	parse_elements(game);
	game_arr = ft_split(game->str, '\n');
	check_rectangular(game, game_arr);
	wall_parse(game, game_arr);
}
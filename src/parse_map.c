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

static void	parse_characters(t_map *map)
{
	char	*map_ptr;

	map_ptr = map->string;
	map->collectibles = 0;
	map->exit_char = 0;
	map->start = 0;
	while (*map_ptr)
	{
		if (*map_ptr != '0' && *map_ptr != '1' && *map_ptr != 'C'
			&& *map_ptr != 'E' && *map_ptr != 'P' && *map_ptr != '\n')
			exit_program(map, "Error\nInvalid characters on Map\n");
		if (*map_ptr == 'C')
			map->collectibles++;
		if (*map_ptr == 'E')
			map->exit_char++;
		if (*map_ptr == 'P')
			map->start++;
		if (*map_ptr++ == '\n' && *map_ptr == '\n')
			exit_program(map, "Error\nWrong map configuration\n");
	}
	if (map->collectibles == 0 || map->exit_char == 0 || map->start == 0)
		exit_program(map, "Error\nMap must contain C, E and P characters\n");
	if (map->exit_char != 1 || map->start != 1)
		exit_program(map, "Error\nThe game must contain 1 player and 1 exit\n");
}
/*Check if the map is rectangular by checking if the lines that compose
the map are of the same size*/

static void	check_rectangular(t_game *game, char **game_arr)
static void	is_rectangular(t_map *map, char **map_array)
{
	int		array_length;
	int		i;
	int		line_length;
	int		temp;

	array_length = array_len(map_array);
	i = 0;
	line_length = ft_strlen(map_array[i]);
	while (++i < array_length)
	{
		temp = ft_strlen(map_array[i]);
		if (line_length != temp)
			free_map_array(array_length, map_array, map, NOT_RECTANGULAR);
	}
}

static int	check_top_and_bottom_wall(char **map_array, int i, int j)
{
	while (map_array[i][j])
	{
		if (map_array[i][j++] != '1')
			return (INVALID_WALL);
	}
	return (VALID_MAP);
}

/*to parse the map take the array and check if top and bottom are
valid (1) and if the first and last char of each line are also valid (1)
if not valid, free array, exit program and show error message*/

static void	parse_walls(t_map *map, char **map_array)
{
	int		array_length;
	int		i;
	int		j;

	array_length = array_len(map_array);
	i = 0;
	j = 0;
	if (check_top_and_bottom_wall(map_array, i, j))
		free_map_array(array_length, map_array, map, INVALID_WALL);
	j = ft_strlen(map_array[0]) - 1;
	while (++i < array_length - 1)
	{
		if (map_array[i][0] != '1')
			free_map_array(array_length, map_array, map, INVALID_WALL);
		if (map_array[i][j] != '1')
			free_map_array(array_length, map_array, map, INVALID_WALL);
	}
	if (check_top_and_bottom_wall(map_array, i, 0))
		free_map_array(array_length, map_array, map, INVALID_WALL);
	free_map_array(array_length, map_array, map, VALID_MAP);
}

void	parse_map(t_map *map)
{
	char	**map_array;

	parse_characters(map);
	map_array = ft_split(map->string, '\n');
	is_rectangular(map, map_array);
	parse_walls(map, map_array);
}

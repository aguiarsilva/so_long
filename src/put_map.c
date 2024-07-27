/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:44:05 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/25 23:44:05 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	read_xpm_to_image(t_map *map)
{
	map->tile.img = mlx_xpm_file_to_image(map->mlx, "../assets/floor.xpm",
			&map->tile.width, &map->tile.height);
	map->wall.img = mlx_xpm_file_to_image(map->mlx, "../assets/wall.xpm",
			&map->wall.width, &map->wall.height);
	map->coin.img = mlx_xpm_file_to_image(map->mlx, "../assets/collectible.xpm",
			&map->coin.width, &map->coin.height);
	map->exit.img = mlx_xpm_file_to_image(map->mlx, "../assets/Exit_barrel.xpm",
			&map->exit.width, &map->exit.height);
	map->player.img = mlx_xpm_file_to_image(map->mlx, "../assets/player.xpm",
			&map->player.width, &map->player.height);
}

static void	put_image_to_window(t_map *map, int x, int y, int i)
{
	if (map->string[i] == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->tile.img, x, y);
	if (map->string[i] == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->wall.img, x, y);
	if (map->string[i] == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->coin.img, x, y);
	if (map->string[i] == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->exit.img, x, y);
	if (map->string[i] == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->player.img, x, y);
}

static void	destroy_image(t_map *map)
{
	mlx_destroy_image(map->mlx, map->tile.img);
	mlx_destroy_image(map->mlx, map->wall.img);
	mlx_destroy_image(map->mlx, map->coin.img);
	mlx_destroy_image(map->mlx, map->exit.img);
	mlx_destroy_image(map->mlx, map->player.img);
}

int	render_map(t_map *map)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	read_xpm_to_image(map);
	while (y < map->height)
	{
		while (x < map->width)
		{
			put_image_to_window(map, x, y, i);
			x += map->tile.width;
			i++;
		}
		x = 0;
		y += map->tile.height;
		i++;
	}
	destroy_image(map);
	return (0);
}

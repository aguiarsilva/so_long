/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 01:42:13 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/23 01:42:13 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Locate player on map, if above is collectible or empty, substitute player for 
the space above. If it is exit and there is no collectible left, exit game*/

static void	move_up(t_map *map)
{
	char	*player;
	char	*char_above;

	player = ft_strchr(map->string, 'P');
	char_above = player - (map->width / SPRITE_SIZE) - 1;
	if (*char_above == 'C' || *char_above == '0')
	{
		*char_above = 'P';
		*player = '0';
		map->movements++;
		printf("Movements: %i\n", map->movements);
	}
	if (*char_above == 'E' && !ft_strchr(map->string, 'C'))
	{
		map->movements++;
		printf("Movements: %i\n", map->movements);
		close_window(map);
	}
}

static void	move_left(t_map *map)
{
	char	*player;

	player = ft_strchr(map->string, 'P');
	player--;
	if (*player == 'C' || *player == '0')
	{
		*player = 'P';
		*++player = '0';
		map->movements++;
		printf("Movements: %i\n", map->movements);
	}
	if (*player == 'E')
	{
		if (!ft_strchr(map->string, 'C'))
		{
			map->movements++;
			printf("Movements: %i\n", map->movements);
			close_window(map);
		}
	}
}

static void	move_down(t_map *map)
{
	char	*player;
	char	*char_below;

	player = ft_strchr(map->string, 'P');
	char_below = player + (map->width / SPRITE_SIZE) + 1;
	if (*char_below == 'C' || *char_below == '0')
	{
		*char_below = 'P';
		*player = '0';
		map->movements++;
		printf("Movements: %i\n", map->movements);
	}
	if (*char_below == 'E')
	{
		if (!ft_strchr(map->string, 'C'))
		{
			map->movements++;
			printf("Movements: %i\n", map->movements);
			close_window(map);
		}
	}
}

static void	move_right(t_map *map)
{
	char	*player;

	player = ft_strchr(map->string, 'P');
	player++;
	if (*player == 'C' || *player == '0')
	{
		*player = 'P';
		*--player = '0';
		map->movements++;
		printf("Movements: %i\n", map->movements);
	}
	if (*player == 'E')
	{
		if (!ft_strchr(map->string, 'C'))
		{
			map->movements++;
			printf("Movements: %i\n", map->movements);
			close_window(map);
		}
	}
}

int	move_player(int keycode, t_map *map)
{
	if (keycode == XK_w || keycode == XK_Up)
		move_up(map);
	if (keycode == XK_a || keycode == XK_Left)
		move_left(map);
	if (keycode == XK_s || keycode == XK_Down)
		move_down(map);
	if (keycode == XK_d || keycode == XK_Right)
		move_right(map);
	render_map(map);
	return (0);
}

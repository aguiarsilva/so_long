/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:16:09 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/21 23:16:09 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* use mlx_destroy functions to make clean exit when pressing
ESC key. */

static int	escape_window(int keycode, t_map *map)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(map->mlx, map->window);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		free(map->string);
		exit(0);
	}
	return (0);
}

/* use mlx_destroy functions to make exit when X on the window is clicked*/

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->window);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free(map->string);
	exit(0);
	return (0);
}

/*keep game running and waiting for events using mlx_hook functions*/

void	receive_events(t_map *map)
{
	mlx_loop_hook(map->mlx, render_map, map);
	mlx_hook(map->window, KeyPress, KeyPressMask, move_player, map);
	mlx_hook(map->window, KeyRelease, KeyReleaseMask, escape_window, map);
	mlx_hook(map->window, DestroyNotify, StructureNotifyMask, close_window,
		map);
	mlx_loop(map->mlx);
}

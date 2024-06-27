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

static int	esc_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game->str);
		exit(0);
	}
	return (0);
}

/* use mlx_destroy functions to make exit when X on the window is clicked*/

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->str);
	exit(0);
	return (0);
}

/*keep game running and waiting for events using mlx_hook functions*/

void	event_receiver(t_game *game)
{
	mlx_loop_hook(game->mlx, put_map, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, sprite_move, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, esc_key, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask,
		close_game, game);
	mlx_loop(game->mlx);
}

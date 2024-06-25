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

static void     conv_xpm_to_img(t_game *game)
{
    game->floor.img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &game->floor.width, &game->floor.height);
    game->wall.img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &game->wall.width, &game->wall.height);
    game->collectible.img = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &game->collectible.width, &game->collectible.height);
    game->exit.img = mlx_xpm_file_to_image(game->mlx, "assets/Exit_barrel.xpm", &game->exit.width, &game->exit.height);
    game->player.img = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &game->player.width, &game->player.height);
}


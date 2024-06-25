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

static void     show_img_to_win(t_game *game, int x, int y, int i)
{
    if (game->str[i] == '0')
        mlx_put_image_to_window(game->mlx, game->window, game->floor.img, x, y);
    if (game->str[i] == '1')
        mlx_put_image_to_window(game->mlx, game->window, game->wall.img, x, y);
    if (game->str[i] == 'C')
        mlx_put_image_to_window(game->mlx, game->window, game->collectible.img, x, y);
    if (game->str[i] == 'E')
        mlx_put_image_to_window(game->mlx, game->window, game->exit.img, x, y);
    if (game->str[i] == 'P')
        mlx_put_image_to_window(game->mlx, game->window, game->player.img, x, y);
}

static void     remove_img(t_game *game)
{
    mlx_destroy_image(game->mlx, game->floor.img);
    mlx_destroy_image(game->mlx, game->wall.img);
    mlx_destroy_image(game->mlx, game->collectible.img);
    mlx_destroy_image(game->mlx, game->exit.img);
    mlx_destroy_image(game->mlx, game->player.img);
}

int     put_map(t_game *game)
{
    int x;
    int y;
    int i;

    x = 0;
    y = 0;
    i = 0;
    conv_xpm_to_img(game);
    while (y < game-> height)
    {
        while (x < game->width)
        {
            show_img_to_win(game, x, y, i);
            x += game->floor.width;
            i++;
        }
        x = 0;
        y += game->floor.height;
        i++;
    }
    remove_img(game);
    return (0);
}
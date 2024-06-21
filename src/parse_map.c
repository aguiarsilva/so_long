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

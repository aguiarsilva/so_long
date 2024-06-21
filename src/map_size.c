/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:51:40 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/21 14:51:40 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int     size_col(t_game *game)
{
    char    *new_line;
    int     col_size;

    new_line = ft_strchr(game->str, '\n');
    if (new_line)
        col_size = new_line - game->str;
    else
        new_line = 0;
    return (col_size);
}

int     size_lin(t_game *game)
{
    char    **game_lns;
    int     arr_len;

    game_lns = ft_split(game->str, '\n');
    arr_len = array_size(game_lns);
    free_game_array(arr_len, game_lns, game, 0);
    return (arr_len);
}
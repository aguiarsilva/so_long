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

static void     go_up(t_game *game)
{
    char    *sprite;
    char    *spot_above;

    sprite = ft_strchr(game->str, 'P');
    spot_above = sprite - (game->width / 16) - 1;
    if (*spot_above == 'C' || *spot_above == '0')
    {
        *spot_above = 'P';
        *sprite = '0';
        game->move++;
        ft_printf("Moves: %i\n", game->move);
    }
    if (*spot_above == 'E' && !ft_strchr(game->str, 'C'))
    {
        game->move++;
        ft_printf("Moves: %i\n", game->move);
        close_game(game);
    }
}

static void     go_left(t_game *game)
{
    char    *sprite;

    sprite = ft_strchr(game->str, 'P');
    sprite--;
    if (*sprite == 'C' || *sprite == '0')
    {
        *sprite = 'P';
        *++sprite = '0';
        game->move++;
        ft_printf("Moves: %i\n", game->move);
    }
    if (*sprite == 'E')
    {
        if (!ft_strchr(game->str, 'C'))
        {
            game->move++;
            ft_printf("Moves: %i\n");
            close_game(game);
        }
    }
}

static void     go_down(t_game *game)
{
    char    *sprite;
    char    *spot_under;

    sprite = ft_strchr(game->str, 'P');
    spot_under = sprite + (game->width / 16) + 1;
    if (*spot_under == 'C' || *spot_under == '0')
    {
        *spot_under = 'P';
        *sprite = '0';
        game->move++;
        ft_printf("Moves: %i\n", game->move);
    }
    if (*spot_under == 'E')
    {
        if (!ft_strchr(game->str, 'C'))
        {
            game->move++;
            ft_printf("Moves: %i\n", game->move);
            close_game(game);
        }
    }
}

static void     go_right(t_game *game)
{
    char    *sprite;

    sprite = ft_strchr(game->str, 'P');
    sprite++;
    if (*sprite == 'C' || *sprite == '0')
    {
        *sprite = 'P';
        *--sprite = '0';
        game->move++;
        ft_printf("Moves: %i\n", game->move);
    }
    if (*sprite == 'E')
    {
        if (!ft_strchr(game->str, 'C'))
        {
            game->move++;
            ft_printf("Moves: %i\n", game->move);
            close_game(game);
        }
    }
}

int     sprite_move(int keycode, t_game *game)
{
    if (keycode == XK_w || keycode == XK_Up)
        go_up(game);
    if (keycode == XK_a || keycode == XK_Left)
        go_left(game);
    if (keycode == XK_s || keycode == XK_Down)
        go_down(game);
    if (keycode == XK_d|| keycode == XK_Right)
        go_up(game);
    render_game(game);
    return (0);
}
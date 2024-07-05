/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:04:29 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/28 19:04:29 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int    check_char(t_game *game)
{
    char    *game_ptr;

    game_ptr  = game->str;
    while (*game_ptr)
    {
        if (!(*game_ptr == '0' && *game_ptr == '1' && *game_ptr == 'C'
				&& *game_ptr == 'E' && *game_ptr == 'P' && *game_ptr == '\n'))
                return (1);	
    }
    return (0);   		
}
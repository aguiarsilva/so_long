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

    
}
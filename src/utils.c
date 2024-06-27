/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:20:23 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/22 00:20:23 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(t_game *game, char *msg)
{
	ft_printf("%s", msg);
	free (game->str);
	exit (1);
}

int	len_array(char **arr)
{
	int	arr_len;

	arr_len = 0;
	while (arr[arr_len])
		arr_len++;
	return (arr_len);
}

void	free_game_array(int arr_len, char **arr, t_game *game, int err)
{
	while (--arr_len >= 0)
		free(arr[arr_len]);
	free(arr);
	if (err == 1)
		exit_game(game, "Error\nThe map is not rectangular\n");
	if (err == 2)
		exit_game(game, "Error\nMap not closed by walls!\n");
}

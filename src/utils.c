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

void	exit_program(t_map *map, char *message)
{
	printf("%s", message);
	free(map->string);
	exit(1);
}

int	array_len(char **array)
{
	int		array_length;

	array_length = 0;
	while (array[array_length])
		array_length++;
	return (array_length);
}

void	free_map_array(int array_length, char **array, t_map *map, int error)
{
	while (--array_length >= 0)
		free(array[array_length]);
	free(array);
	if (error == NOT_RECTANGULAR)
		exit_program(map, "Error\nThe map is not rectangular\n");
	if (error == INVALID_WALL)
		exit_program(map, "Error\nMap not closed by walls!\n");
}

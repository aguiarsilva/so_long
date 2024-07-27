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

int	measure_columns(t_map *map)
{
	char	*ptr_to_newline;
	int		line_size;

	ptr_to_newline = ft_strchr(map->string, '\n');
	if (ptr_to_newline)
		line_size = ptr_to_newline - map->string;
	else
		line_size = 0;
	return (line_size);
}

int	measure_lines(t_map *map)
{
	char	**map_lines;
	int		array_length;

	map_lines = ft_split(map->string, '\n');
	array_length = array_len(map_lines);
	free_map_array(array_length, map_lines, map, 0);
	return (array_length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:02:27 by baguiar-          #+#    #+#             */
/*   Updated: 2024/06/14 15:02:27 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_error_and_exit(char *message)
{
	printf("%s\n", message);
	exit(1);
}

int	open_map(int argc, char *argv[])
{
	int		file_descriptor;
	char	*file_format;

	if (argc != 2)
		print_error_and_exit("Error\n The program must have one argument\n");
	file_format = ft_strrchr(argv[1], '.');
	if (!file_format)
		print_error_and_exit("Error\n Invalid file format\n");
	else
	{
		if (ft_strncmp(file_format, ".ber", ft_strlen(file_format)) != 0)
			print_error_and_exit("Error\n Invalid file format\n");
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		perror("Error\n");
		exit(1);
	}
	return (file_descriptor);
}

char	*read_map(int file_descriptor)
{
	char	*map;
	int		lines_read;
	char	*line;
	char	*temp;

	map = ft_strdup("");
	lines_read = 0;
	while (++lines_read)
	{
		line = get_next_line(file_descriptor);
		if (line == NULL)
			break ;
		temp = ft_strjoin(map, line);
		free(map);
		map = ft_strdup(temp);
		free(temp);
		free(line);
	}
	return (map);
}

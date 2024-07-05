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

void	exit_error(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit(1);
}

int	open_map(int argc, char **argv)
{
	int		fd;
	char	*format;

	if (argc != 2)
		exit_error("Error\n The program must have one argument\n");
	format = ft_strrchr(argv[1], '.');
	if (!format)
		exit_error("Error\n Invalid file format\n");
	else
	{
		if (ft_strncmp(format, ".ber", ft_strlen(format)) != 0)
			exit_error("Error\n Invalid file format\n");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (fd);
}

char	*map_read(int fd)
{
	char	*map;
	int		rd_line;
	char	*line;
	char	*temp;

	map = ft_strdup("");
	rd_line = 0;
	while (++rd_line)
	{
		line = get_next_line(fd);
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

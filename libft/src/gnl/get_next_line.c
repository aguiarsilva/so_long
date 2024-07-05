/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:19:46 by baguiar-          #+#    #+#             */
/*   Updated: 2024/07/05 12:00:07 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"
#include "../../inc/libft.h"

static char	*get_line(char **static_buffer)
{
	char	*ptr_to_newline_char;
	size_t	line_size;
	char	*line;
	char	*temp_buffer;

	if (*static_buffer == NULL)
		return (NULL);
	ptr_to_newline_char = ft_strchr(*static_buffer, '\n');
	if (ptr_to_newline_char)
	{
		line_size = (ptr_to_newline_char - *static_buffer) + 1;
		line = ft_substr(*static_buffer, 0, line_size);
		ptr_to_newline_char++;
		temp_buffer = ft_strdup(ptr_to_newline_char);
		free(*static_buffer);
		*static_buffer = ft_strdup(temp_buffer);
		free(temp_buffer);
		return (line);
	}
	else
		return (NULL);
}

/*
** NAME
** 		assign_line - assign a string to the static variable line
** DESCRIPTION
** 		Receive bytes read from a previous call to read on file descriptor,
** 		and the addresses of the static variables static_buffer, buffer
** 		and line, which were initialized in get_next_line.
**
** 		If read was successfully called, join buffer to static_buffer,
** 		call get_line to check if there is a line on the string created.
** 		If a line was found, assign it to static variable line.
**
** 		If read returned EOF, and there is a string stored on static_buffer,
** 		assign it to line and set static_buffer to NULL.
*/

static void	assign_line(int bytes, char **sta_buf, char **buf, char **line)
{
	char	*temp;

	if (bytes > 0)
	{
		if (*sta_buf == NULL)
			*sta_buf = ft_strdup("");
		temp = ft_strjoin(*sta_buf, *buf);
		free(*sta_buf);
		*sta_buf = ft_strdup(temp);
		free(temp);
		*line = get_line(sta_buf);
	}
	free(*buf);
	if (bytes <= 0 && *sta_buf != NULL)
	{
		if (**sta_buf != '\0')
			*line = ft_strdup(*sta_buf);
		free(*sta_buf);
		*sta_buf = NULL;
	}
}

/*
** NAME
** 		get_next_line
** DESCRIPTION
** 		A function which returns a line read from a
** 		file descriptor
** RETURN VALUE
** 		Read line: correct behavior
** 		NULL: nothing else to read or an error occurred
*/

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*static_buffer;
	char			*line;
	int				bytes_read;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(&static_buffer);
	while (line == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		assign_line(bytes_read, &static_buffer, &buffer, &line);
		if (bytes_read <= 0 && static_buffer == NULL)
			break ;
	}
	return (line);
}

/*char	*fill_line(int fd, char *lchar, char *buf);
char	*put_line(char *line_buf);

char	*get_next_line(int fd)
{
	static char	*lchar[MAX_FD];
	char		*buf;
	char		*line;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buf);
		free(lchar[fd]);
		buf = NULL;
		lchar[fd] = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fill_line(fd, lchar[fd], buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	lchar[fd] = put_line(line);
	return (line);
}

char	*fill_line(int fd, char *lchar, char *buf)
{
	ssize_t	byte;
	char	*temp;

	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free(lchar);
			return (NULL);
		}
		else if (byte == 0)
			break ;
		buf[byte] = 0;
		if (!lchar)
			lchar = ft_strdup("");
		temp = lchar;
		lchar = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (lchar);
}

char	*put_line(char *line_buf)
{
	char	*stack;
	ssize_t	i;

	i = 0;
	while (line_buf[i] != '\n' && line_buf[i] != '\0')
	{
		i++;
	}
	if (line_buf[i] == 0 || line_buf[1] == 0)
		return (0);
	stack = ft_substr(line_buf, i + 1, ft_strlen(line_buf) - i);
	if (*stack == 0)
	{
		free(stack);
		stack = NULL;
	}
	line_buf[i + 1] = 0;
	return (stack);
}*/

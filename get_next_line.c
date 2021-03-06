/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:22:12 by antonmar          #+#    #+#             */
/*   Updated: 2020/12/02 11:01:12 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_file(char **file)
{
	(*file) ? free(*file) : NULL;
	*file = NULL;
	return (0);
}

int		newline_pos(char *file)
{
	int i;

	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
		i++;
	return (i);
}

void	file_filler(char **file, char *buffer)
{
	char		*temp;

	if (*file == NULL)
		*file = ft_strdup(buffer);
	else
	{
		temp = *file;
		*file = ft_strjoin(*file, buffer);
		(temp) ? free(temp) : NULL;
		temp = NULL;
	}
}

void	line_filler(char **line, char **file)
{
	char		*temp;

	temp = *file;
	*line = ft_substr(*file, 0, newline_pos(*file));
	*file = ft_substr(*file, newline_pos(*file) + 1, ft_strlen(*file));
	(temp) ? free(temp) : NULL;
	temp = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char	*file[4096];
	char		*buffer;
	int			buffer_tam;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL ||
		!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	buffer_tam = 1;
	while (!(ft_strchr(file[fd], '\n')) && buffer_tam != 0)
	{
		if ((buffer_tam = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[buffer_tam] = '\0';
		file_filler(&file[fd], buffer);
	}
	free(buffer);
	line_filler(line, &file[fd]);
	if (buffer_tam == 0)
		return (free_file(&file[fd]));
	return (1);
}

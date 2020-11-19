/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:22:12 by antonmar          #+#    #+#             */
/*   Updated: 2020/11/19 11:26:46 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		newline(char *file)
{
	int i;

	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
		i++;
	return (i);
}

void	file_filler(char **file, char *buffer, int fd)
{
	char		*temp;

	if (file[fd] == NULL)
		file[fd] = ft_strdup(buffer);
	else
	{
		temp = file[fd];
		file[fd] = ft_strjoin(file[fd], buffer);
		if (temp)
			free(temp);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*file[4096];
	char		*buffer;
	int			buffer_tam;
	char		*temp;

	buffer_tam = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!(ft_strchr(file[fd], '\n')) && buffer_tam != 0)
	{
		if ((buffer_tam = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[buffer_tam] = '\0';
		file_filler(file, buffer, fd);
	}
	free(buffer);
	temp = file[fd];
	*line = ft_substr(file[fd], 0, newline(file[fd]));
	file[fd] = ft_substr(file[fd], newline(file[fd]) + 1, ft_strlen(file[fd]));
	temp ? free(temp) : NULL;
	if (buffer_tam == 0)
		return (0);
	return (1);
}

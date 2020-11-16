/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:22:12 by antonmar          #+#    #+#             */
/*   Updated: 2020/11/16 14:48:36 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		newline(char *file)
{
	int i;

	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
		i++;
	return (i);
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
	free(buffer);
	temp = file[fd];
	*line = ft_substr(file[fd], 0, newline(file[fd]));
	file[fd] = ft_substr(file[fd], newline(file[fd]) + 1, ft_strlen(file[fd]));
	if (temp)
		free(temp);
	if (buffer_tam == 0)
		return (0);
	return (1);
}

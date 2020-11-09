/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:23:02 by antonmar          #+#    #+#             */
/*   Updated: 2020/11/09 12:45:51 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(size + 1);
	i = -1;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (++i < ft_strlen((char *)s1))
		str[i] = s1[i];
	while (i < size)
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *string)
{
	int		i;
	void	*tams;

	i = 0;
	tams = malloc(ft_strlen(string) + 1);
	if (tams != NULL)
	{
		while (i < ft_strlen(string) + 1)
		{
			((char *)tams)[i] = string[i];
			i++;
		}
	}
	return (tams);
}

char	*ft_strchr(const char *str, int c)
{
	char *s;

	if (!str)
		return (0);
	s = (char *)str;
	while (*(s) != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	str = malloc(len + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < len && start < (unsigned int)ft_strlen((char *)s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

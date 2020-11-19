/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:23:02 by antonmar          #+#    #+#             */
/*   Updated: 2020/11/19 11:20:10 by antonmar         ###   ########.fr       */
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

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		size;
	int		size1;
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen((char *)s1);
	size = size1 + ft_strlen((char *)s2);
	str = malloc(size + 1);
	i = -1;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (++i < size1)
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

char	*ft_strdup(char *string)
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
	unsigned int	length;

	if (!s)
		return (0);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	length = (unsigned int)ft_strlen((char *)s);
	while (i < len && start < length)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

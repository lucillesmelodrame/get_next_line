/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:23:42 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/09 12:30:34 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*my_calloc(size_t n, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (n == 0 || size == 0)
	{
		tmp = malloc(1);
		return (tmp);
	}
	if (n > (size_t) - 1 / size)
		return (NULL);
	tmp = malloc(n * size);
	if (!tmp)
		return (NULL);
	while (i < n * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = my_calloc((my_strlen(s1) + my_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}

char	*find_newline(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if ((unsigned char)str[i] == '\n')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = my_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	return (str);
}

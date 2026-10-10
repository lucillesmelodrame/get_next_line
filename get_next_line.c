/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:13:56 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/11 02:25:28 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	size_t	len;
	char	*line;
	char	*n1;
	char	*tmp;

	stash = read_to_stash(fd, stash);
	n1 = find_newline(stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (n1)
		len = n1 - stash + 1;
	else
		len = my_strlen(stash);
	line = my_substr(stash, 0, len);
	if (!line)
		return (NULL);
	tmp = my_substr(stash, len, (my_strlen(stash) - len));
	free(stash);
	if (!tmp)
	{
		free(line);
		stash = NULL;
		return (NULL);
	}
	stash = tmp;
	return (line);
}

char	*read_to_stash(int fd, char *stash)
{
	ssize_t	ret;
	char	*buf;

	buf = my_calloc(BUFFER_SIZE + 1, sizeof(char));
	ret = 1;
	if (!buf)
	{
		free(stash);
		return (NULL);
	}
	while (!find_newline(stash) && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(stash);
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		stash = append_to_stash(stash, buf);
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (stash);
}

char	*append_to_stash(char *stash, char *buf)
{
	char	*tmp;

	tmp = my_strjoin(stash, buf);
	free(stash);
	if (!tmp)
		return (NULL);
	return (tmp);
}

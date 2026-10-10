/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:16:16 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/09 12:27:46 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 1
#  error "Invalid buffer size"
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
void	*my_calloc(size_t n, size_t size);
int	has_newline(const char *str);
size_t	my_strlen(const char *str);
char	*my_strjoin(char const *s1, char const *s2);
char	*read_to_stash(int fd, char *stash);
char	*append_to_stash(char *stash, char *buf);
char	*find_newline(const char *str);
char	*my_substr(char const *s, unsigned int start, size_t len);

#endif

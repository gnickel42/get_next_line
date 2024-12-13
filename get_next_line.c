/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:40:11 by gnickel           #+#    #+#             */
/*   Updated: 2024/11/04 10:40:23 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_nl(int fd, char **buf, char *line)
{
	size_t	b_read;
	char	*temp;
	char	*nl;

	nl = ft_strchr(*buf, '\n');
	temp = 0;

}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	if (!buf)
		buf = ft_strdup("");

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:40:11 by gnickel           #+#    #+#             */
/*   Updated: 2024/12/18 16:06:31 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_ln(int nl, char **buf)
{
	char	*res;
	char	*temp;

	temp = 0;
	if (nl <= 0)
	{
		if (**buf == '\0')
		{
			free(*buf);
			return (*buf = 0);
		}
		res = *buf;
		*buf = 0;
		return (res);
	}
	temp = ft_substr(*buf, nl, BUFFER_SIZE);
	res = *buf;
	res[nl] = 0;
	*buf = temp;
	return (res);
}

char	*find_nl(int fd, char **buf, char *line)
{
	int		b_read;
	char	*temp;
	char	*nl;

	nl = ft_strchr(*buf, '\n');
	temp = 0;
	b_read = 0;
	while (nl == 0)
	{
		b_read = read(fd, line, BUFFER_SIZE);
		if (b_read == 0)
			break ;
		if (b_read == -1)
			return (0);
		line[b_read] = 0;
		temp = ft_strjoin(*buf, line);
		free(*buf);
		*buf = temp;
		nl = ft_strchr(*buf, '\n');
	}
	return (join_ln(nl - *buf, buf));
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
	ret = find_nl(fd, &buf, line);
	free(line);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:40:11 by gnickel           #+#    #+#             */
/*   Updated: 2024/12/18 17:02:30 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <wctype.h>

static  char *update_carry(char *line, char *nl, char *carry)
{
	char *temp;
	char *ret;
	int i;

	ret = malloc(nl - line + 1);
	i = -1;
	while (line + (++i) < nl)
		ret[i] = line[i];
	ret[i] = 0;
	i = -1;
	while (nl[++i])
		carry[i] = nl[i];
	carry[i] = 0;
	return (free(line), ret);
}

static  char *handle_eof()
{

}

static char *handle_start_carry()
{

}

static char *helper_join(char *str1, char *str2)
{
	char *temp;
	temp = ft_strjoin(str1, str2);
	free(str1);
	return (temp);
}

char	*get_next_line(int fd)
{
	static  char carry[BUFFER_SIZE + 1] = {0};
	char buffer[BUFFER_SIZE + 1] = {0};
	char	*line;
	ssize_t	b_read;
	char *nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = handle_start_carry();
	if (line)
		return line;
	line = ft_strdup("");
	if (!line)
		return (NULL);
	nl = NULL;
	while (!nl)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == 0)
			return (handle_eof()) ;
		if (b_read == -1)
			return (free(line), NULL);
		buffer[b_read] = 0;
		line = helper_join(line, buffer);
		nl = ft_strchr(line, '\n');
	}
	return (update_carry(line, nl, carry));
}

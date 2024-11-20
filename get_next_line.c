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

int	newline_check(t_buffer *head)
{
	while (head)
	{
		if (ft_strchr(head->buffer, '\n'))
			return (1);
		head = head->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer	*head;
	char			tmp[BUFFER_SIZE + 1];
	char			*line;
	int				b_read;

	while (!newline_check(head))
	{
		b_read = read(fd, tmp, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		tmp[b_read] = '\0';
	}
	return (line);
}

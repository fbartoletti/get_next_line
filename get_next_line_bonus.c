/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:05:01 by marvin            #+#    #+#             */
/*   Updated: 2024/04/03 11:05:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *all)
{
	char	*buf;
	int		nbyte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nbyte = 1;
	while (nbyte != 0 && !ft_stop(all, '\n'))
	{
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nbyte] = '\0';
		all = ft_strjoin(all, buf);
		if (nbyte < BUFFER_SIZE)
			break;
	}
	free(buf);
	return (all);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*all[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all[fd] = ft_read_line(fd, all[fd]);
	if (!all[fd])
		return (NULL);
	line = ft_take_line(all[fd]);
	all[fd] = ft_save(all[fd]);
	return (line);
}

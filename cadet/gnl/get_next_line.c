/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/01/03 18:38:15 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{	
	static char	*buffer;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 0)
	{
		return (-1);
	}
	buffer = read_line(fd, buffer);
	if (buffer == 0)
	{
		return (0);
	}
	line = read_string(buffer);
	buffer = new_buffer(buffer);
	return (line);
}

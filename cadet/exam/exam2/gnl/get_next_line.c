/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:56:03 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/12 17:08:34 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *gnl(size_t size, int fd)
{
	char *ret, word_one = 0, read_word = read(fd, &word_one, 1);
	if (read_word <= 0 || size == 0)
	{
		return (NULL);
	}
	if (read_word == 0 || word_one == '\n')
	{
		ret = malloc(size + 2);
	}
	else
	{
		ret = gnl(size + 1, fd);
	}
	if (ret)
	{
		ret[size] = word_one;
		ret[size + 1] = ret[size + 1] * (word_one != '\n');
	}
	return ret;
}

char *get_next_line(int fd)
{
	return (gnl(0, fd));
}

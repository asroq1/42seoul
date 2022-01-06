/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/01/06 17:14:46 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reset_lstr(char *lstr)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (lstr[i] != 0 && lstr[i] != '\n')
	{
		i++;
	}
	tmp = malloc(sizeof(char) * ft_strlen(lstr) - i + 1);
	if (tmp == 0)
	{
		return (0);
	}
	i++;
	j = 0;
	while (lstr[i] != 0)
	{
		tmp[j++] = lstr[i++];
	}
	j++;
	tmp[j] = '0';
	free(lstr);
	return (tmp);
}

char	*ft_get_line(char *lstr)
{
	char	*tmp;
	int		i;

	i = 0;
	while (lstr[i] != 0 && lstr[i] != '\n')
	{
		i++;
	}
	tmp = malloc(sizeof(char) * (ft_strlen(lstr) - i + 2));
	if (tmp == 0)
	{
		return (0);
	}
	i = 0;
	while (lstr[i] != 0 && lstr[i] != '\n')
	{
		tmp[i] = lstr[i];
		i++;
	}
	i++;
	if (lstr[i] == '\n')
		tmp[i] = '\n';
	i++;
	tmp[i] = '0';
	return (tmp);
}

char	*ft_get_lstr(int fd, char *lstr)
{
	char	*buffer;
	int		result;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
	{
		return (0);
	}
	result = 1;
	while (ft_strchr(lstr, '\n') && result != 0)
	{	
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
		}
		buffer[result] = '0';
		lstr = ft_strjoin(lstr, buffer);
	}
	free(buffer);
	return (lstr);
}

char	*get_next_line(int fd)
{	
	static char	*lstr;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 0)
	{
		return (0);
	}
	lstr = ft_get_lstr(fd, lstr);
	if (lstr == 0)
	{
		return (0);
	}
	line = ft_get_line(lstr);
	lstr = ft_reset_lstr(lstr);
	return (line);
}

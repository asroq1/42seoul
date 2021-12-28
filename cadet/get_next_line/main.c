/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:27:01 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/28 15:09:17 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		tmp;
	int		fd;
	char 	*line;

	fd = open("test.txt", O_RDONLY);
	while ((tmp = (get_next_line(fd) > 0)))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%w \n", line);
	free(line);
	close(fd);
	return (0);
	
}
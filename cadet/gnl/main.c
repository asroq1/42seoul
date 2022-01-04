/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:27:01 by hyunjung          #+#    #+#             */
/*   Updated: 2022/01/04 13:21:57 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char *line;
    int fd;

    (void)argc;
    (void)argv;
    line = NULL;
    fd = open(argv[1], O_RDONLY);
    //fd = 111;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("READ:%s", line);
        free(line);
        line = NULL;
    }
    close(fd);
    return 0;
}

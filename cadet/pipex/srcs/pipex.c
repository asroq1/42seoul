/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:17:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/15 17:59:09 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	main(int argc, char **argv, char **envp)
// {

// }
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>

int main(void)
{
    int fd[2];
    int fd_temp;
    char buffer[7];

    pipe(fd);
    fd_temp = dup(fd[1]);
    printf("fd[1]: %d\nfd_temp: %d\n", fd[1], fd_temp);

    /* fd_temp에 입력해보기 */
    write(fd_temp, "Hello\n", 7);
    read(fd[0], buffer, 7);
    printf("fd[0] => %s\n", &fd);
    printf("buffer => %s", buffer);

	close(fd[0]);
	close(fd[1]);
	close(fd_temp);
}
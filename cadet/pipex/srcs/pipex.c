/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:17:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/18 19:01:34 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	parentProc()
// {

// }

// void	parentProc()
// {

// }

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if(pipe(fd) == -1)
		{
			printf("err");
		}
		if (pid == -1)
			printf("err");
		if (pid == 0)
		{
			printf("success fork\n");
			printf("argv => %s envp => %s", argv[1], envp[0]);
		}
	}
	return (0);
}

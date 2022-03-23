/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:17:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/23 18:53:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childProc(char **argv, char **envp, int *pipe)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	printf("infile is => %d\n", infile);
	if (infile == -1)
	{
		error();
	}
	dup2(infile, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0]);
	execute(argv[2], envp);
}

void	parentProc(char **argv, char **envp, int *pipe)
{
	int	outfile;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		error();
	}
	dup2(pipe[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	// i = 0;
	// while (i < argc)
	// {
	// 	printf("path => %s\n", envp[i]);
	// 	printf("\n");
	// 	i++;
	// }
	// char *arr[] = {"ls", "-al", NULL};
	// int returnv = execve("/bin/ls", arr, envp);
	// printf("value = %d\n", returnv);
	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			error();
		}
		pid = fork();
		if (pid == -1)
		{
			error();
		}
		if (pid == 0)
		{
			childProc(argv, envp, fd);
		}
		waitpid(pid, 0, 0);
		parentProc(argv, envp, fd);
	}
	return (0);
}

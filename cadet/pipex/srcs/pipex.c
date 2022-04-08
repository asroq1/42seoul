/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:17:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/04/07 15:03:44 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *argv, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(argv, ' ');
	path = get_path(command[0], envp);
	if (command == 0)
	{
		error();
	}
	if (execve(path, command, envp) == -1)
	{
		error();
	}
}

void	child_proc(char **argv, char **envp, int *pipe, int infile)
{
	dup2(infile, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0]);
	execute(argv[2], envp);
}

void	parent_proc(char **argv, char **envp, int *pipe, int outfile)
{
	dup2(pipe[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid;

	infile = open(argv[1], O_RDONLY, 0777);
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (infile == -1 || outfile == -1)
		error();
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_proc(argv, envp, fd, infile);
		waitpid(pid, 0, WNOHANG);
		parent_proc(argv, envp, fd, outfile);
	}
	return (0);
}

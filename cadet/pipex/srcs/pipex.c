/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:17:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/17 18:27:13 by hyunjung         ###   ########.fr       */
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
	pid_t	pid;
	int		fd[2];

	// if (argc == 5)
	// {
			printf("pid is => %d", pid);
			
		if (pipe(pid) == -1)
			// errorMessage();
			printf("error!");
		if (pid == -1)
			// errorMessage();
		if (pid == 0)
		{
			printf("success!");
			// childProc();
		}
		// waitpid();
		// parentProc();
	// }
	// else
	// {
	// 		printf("else error!");
	// }
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:17:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/29 11:14:18 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *argv, char **envp)
{
	char	**command;
	char	*path;
	// 1.argv를 통해서 들어온 커맨드를 split해서 command[0], command[1]에 담아준다.
	command = ft_split(argv, ' ');
	// 2. command[0]인 ls의 실행 경로를 get_path함수를 통해 추출해 path에 담아준다.
	path = get_path(command[0], envp);
	if (command == 0)
	{
		error();
	}
	// 3. execve함수를 통해 해당 명령어를 실행시켜준다.
	if (execve(path, command, envp) == -1)
	{
		error();
	}
}

void	childProc(char **argv, char **envp, int *pipe)
{
	int	infile;
	// 1.infile 변수에는 fd값이 담겨있다.
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		error();
	}
	// 2. dup2함수를 통해 스트림입력을 infile로 바꾼다.
	dup2(infile, STDIN_FILENO);
	// 3.dup2함수를 통해 스트림출력을 pipe[1]으로 바꾼다
	// 즉 < infile ls -l의 스트림출력을 | 를 통해 wc -l의 입력으로 준다.
	dup2(pipe[1], STDOUT_FILENO);
	// 4. 쓰지 않는 파이프는 닫아주고 ls -l을 excute함수로 실행시킨다.
	close(pipe[0]);
	execute(argv[2], envp);
}

void	parentProc(char **argv, char **envp, int *pipe)
{
	int	outfile;
	// 1.outfile 변수에는 fd값이 담겨있다.
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		error();
	}
	// 2. pipe[0]를 스트림 입력으로 바꾼다.
	// child에서 pipe[1]의 출력을 다시 입력으로 받기 위해서다.
	dup2(pipe[0], STDIN_FILENO);
	// 3. 스트림 출력을 outfile로 바꿔준다.
	dup2(outfile, STDOUT_FILENO);
	close(pipe[1]);
	// 4. 쓰지 않는 파이프를 닫고, wc -l 함수를 실행한다.
	// 그러면 < infile ls -l로 들어온 인풋값을 리다이렉션으로 wc -l로 실행한 후,
	// 스트림 출력을 oufile에다가 한다.
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	// 1.fd[2]인 이유는 파이프는 오직 0읽기, 1쓰기만 있기 때문에
	int		fd[2];
	// 2.안정성을 위해 pit_t형으로 pid변수를 선언
	pid_t	pid;

	if (argc == 5)
	{
		// 3.pipe함수에다가 fd배열을 넣어준다
		if (pipe(fd) == -1)
		{
			error();
		}
		// 4. fork()함수를 통해서 pid라는 자식 프로세스를 만든다.
		pid = fork();
		if (pid == -1)
		{
			error();
		}
		if (pid == 0)
		{
			//5. 자식 프로세스가 잘 생성됐다면 childProc함수를 실행한다.
			childProc(argv, envp, fd);
		}
		// 6.자식 프로세스가 종료될 때까지
		// 부모의 실행을 기다리고, 자식이 끝나면 부모가 실행된다.
		waitpid(pid, 0, 0);
		parentProc(argv, envp, fd);
	}
	return (0);
}

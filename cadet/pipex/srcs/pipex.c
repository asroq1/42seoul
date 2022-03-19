/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:17:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/19 18:24:18 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	childProc()
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
		if (pipe(fd) == -1)
		{
			printf("err");
		}
		pid = fork();
		if (pid == -1)
			printf("err");
		if (pid == 0)
		{
			// childProc(argv, envp, fd);
			printf("argv => %s envp => %s\n", argv[1], envp[0]);
		}
	}
	return (0);
}



int main(void){
        int fd1, ret;
        char message[32]={"STDERR from fd1\n"};

        //그림 1번
        fd1=open("made_by_fd1",O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
        if(fd1<0){
                printf("file open error\n");
                exit(0);
        }
        //표준 입출력으로 print됨
        printf("file open\n");

        //fd1의 파일 디스크립터가 명시한 STDOUT_FILENO의 파일 디스크립터로
        //복제됨,
        //그림 2번
        ret=dup2(fd1,STDOUT_FILENO);

        //fd1으로 출력됨
        printf("fd1 :%d, ret:%d\n",fd1,ret);

        //STDERR_FILENO 디스크립터가 명시된 fd1으로 복제됨
        //그림 3번
        ret=dup2(STDERR_FILENO,fd1);

        //fd1은 에러로 출력됨
        write(fd1,message,strlen(message));

        //stdout이 file로 써짐
        printf("printf를 썼지만 파일에 기록됨 \n");

        close(fd1);

}
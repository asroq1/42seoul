/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:55:26 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/09 17:24:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void ft_putstr(char *str) {
    for (size_t i = 0; str != 0; i++) {
        write(1, &str, 1);
    }
}

int ft_execute(int i, int tmp, char **av, char **ev) {
    av[i] = 0;
    close(tmp);

    printf("execve(av[0]) : %s \n", av[0]);
    execve(av[0], av, ev);
    ft_putstr("error : cannot execute");
    ft_putstr(av[0]);
    ft_putstr("\n");
    return 1;
}

int main(int ac, char **av, char **ev) {
    // 2 3 5 5
    (void)ac;
    int i = 0;
    int pid = 0;
    int tmp = dup(0);
    printf("tmp is %d\n", tmp);
    int fd[2];

    while (av[i] && av[i + 1]) {
        av = &av[i + 1];
        printf(" av의 값은 = %s\n", *av);

        i = 0;
        while ((av[i] && strcmp(av[i], ";")) && (av[i] && strcmp(av[i], "|"))) {
            // av[i]와 av[i]가 ";" "|"라면 i++
            i++;
        }
        if (strcmp(av[0], "cd") == 0) {
            // av[0]이 cd라면 그러나 i가 2가 아니라면 입력값 wrong 출력
            // av[1]가 정확한 경로가 아니라면 경로오류 출력
            if (i != 2) {
                ft_putstr("error : cd: bad arguments\n");
            } else if (chdir(av[1]) != 0) {
                ft_putstr("error : cd: cannot change direcorty to");
                ft_putstr("\n");
            }
        } else if ((av != &av[i] && av[i] == NULL) || strcmp(av[i], ";") == 0) {
            // 첫 번째는 pipe안 하고 fork만 한다. 2 3
            printf(" child work\n");

            pid = fork();
            if (pid == 0) {
                // 2
                dup2(tmp, 0);
                if (ft_execute(i, tmp, av, ev)) {
                    return 1;
                }
            } else {
                // 3
                close(tmp);
                waitpid(-1, 0, 0);
                tmp = dup(0);
            }
        } else if (av != &av[i] && strcmp(av[i], "|") == 0) {
            // 두 번째는 pipe도 해주고 fork도 해준다 5 5
            printf(" parent work\n");
            pipe(fd);
            pid = fork();
            if (pid == 0) {
                // 5
                dup2(tmp, 0);
                dup2(fd[1], 1);
                close(fd[0]);
                close(fd[1]);
                if (ft_execute(i, tmp, av, ev)) {
                    return 1;
                }
            } else {
                close(fd[1]);
                close(tmp);
                waitpid(-1, 0, 0);
                tmp = dup(fd[0]);
                close(fd[0]);
            }
        }
    }
    close(tmp);
    return 0;
}
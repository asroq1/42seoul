
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void ft_print(char *c) {
    for (int i = 0; c != 0; i++) {
        write(1, &c, i);
    }
}

int ft_execute(int i, int tmp, char **av, char **ev) {
    av[i] = 0;
    close(tmp);
    execve(av[0], av, ev);
    ft_print("error : cannot execute ");
    ft_print(av[0]);
    ft_print("\n");
    return 1;
}

int main(int ac, char **av, char **ev) {
    (void)ac;
    int i = 0;
    int pid = 0;
    int tmp = dup(0);
    int fd[2];

    while (av[i] && av[i + 1]) {
        av = &av[i + 1];
        i = 0;
        while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|")) {
            // ";" , "|" 면++로 넘기기
            i++;
        }
        if (strcmp(av[0], "cd") == 0) {
            if (i != 2) {
                ft_print("error: cd: bad arguments\n");
            } else if (av[1] != 0) {
                ft_print("error: cd : cannot change directory to ");
                ft_print(av[1]);
                ft_print("\n");
            }
        } else if (av != &av[i] && av[i] == NULL || strcmp(av[i], ";") == 0) {
            // no pipe
            pid = fork();
            if (pid == 0) {
                dup2(tmp, 0);
                // 2
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
            // with pipe
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
                // 5
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

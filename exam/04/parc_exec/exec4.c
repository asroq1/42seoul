
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int g_fd;

static int exec(int i, char **av, char **ev) {
    int fd[2];
    int pid;
    int status;
    int next = 0;

    if (av[i] && strcmp(av[i], "|") == 0) {
        next = 1;
    }
    if (av[i] == *av) {
        return 0;
    }
    if (pipe(fd) == -1) {
        return ft_print("error: fatal\n");
    }
    pid = fork();
    if (pid == -1) {
        return ft_print("error: fatal\n");
    } else if (pid == 0) {
        close(fd[0]);
        dup2(g_fd, 0);
        av[i] = 0;
        if (next) {
            dup2(fd[1], 1);
        }
        if (g_fd != 0) {
            close(g_fd);
        }
        close(fd[1]);
        if (execve(*av, av, ev) == -1) {
            ft_print("error: cannot execute ");
            ft_print(*av);
            ft_print("\n");
            exit(0);
        }
    } else {
        close(fd[1]);
        waitpid(pid, &status, 0);
        if (g_fd != 0) {
            close(g_fd);
        }
        if (next) {
            g_fd = dup(fd[0]);
        }
        close(fd[0]);
    }
    return 0;
}
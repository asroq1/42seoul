

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int g_fd;

static int ft_print(char *str) {
    int i = 0;
    while (str[i] != 0) {
        write(2, &str[i], 1);
        i++;
    }
    return 1;
}

static int exec_cd(char **av) {
    if (av[2] && strcmp(av[2], "|") != 0 && strcmp(av[2], ";") != 0) {
        ft_print("error: cd: bad arguments\n");
    }
    if (chdir(av[1]) == -1) {
        ft_print("error: cannot execute cd\n");
    }
    return 0;
}

static int exec(int i, char **av, char **ev) {
    int fd[2];
    int status;
    int next = 0;
    int pid;

    if (av[i] && strcmp(av[i], "|") == 0) {
        next = 1;
    }
    if (av[i] == *av) {
        return 0;
    }
    if (pipe(fd) == -1) {
        ft_print("error: fatal\n");
    }
    pid = fork();
    if (pid == -1) {
        ft_print("error: fatal\n");
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
        if (execve(*av, av, ev)) {
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

int main(int ac, char **av, char **ev) {
    int i = 1;
    if (ac == 1) {
        return 0;
    }
    av[ac] = 0;
    while (av[i - 1] && av[i]) {
        // printf(" av[%d] => %s\n", i, *av);
        av = av + i;

        i = 0;
        while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0) {
            i++;
        }
        if (!strcmp(*av, "cd")) {
            exec_cd(av);
        } else {
            exec(i, av, ev);
        }
        i++;
    }
}

static int exec(int ac, char **av, char **ev) {
    int fd[2];
    int status;
    int pid;
    int next = 0;

    else if (pid == 0) {
        close(fd[0]);
        dup2(g_fd, 0);
        av[i] = 0;

        if (next) {
            dup2(fd[1], 1);
        }
        if (g_fd != 0) {
            close(g_fd);
        }
        if (execve(*av, av, ev) == -1) {
            printf();
            printf();
            printf();
            exit(0);
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
    }
    return 0;
}
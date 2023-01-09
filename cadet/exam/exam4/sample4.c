#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void ft_print(char *str) {
    for (int i = 0; str != 0; i++) {
        write(2, &str, 1);
    }
}

int ft_execute(int i, int tmp, char **av, char **ev) {
    av[i] = 0;
    close(tmp);
    execve(av[0], av, ev);
    ft_print("error : cannot execute");
    ft_print(av[i]);
    ft_print("\n");
    return 1;
}
int main(int ac, char **av, char **ev) {
    (void)ac;
    int i = 0;
    int pid = 0;
    int tmp = dup(0);
    int fd[2];

    while (av && av[i + 1]) {
        av = &av[i + 1];
        while ((av[i] && strcmp(av[i], ";")) && (av[i] && strcmp(av[i], "|"))) {
            i++;
        }
        if (strcmp(av[0], "cd") == 0) {
            if (i != 2) {
                ft_print("error : cd: wrong argc");
            } else if (chdir(av[1]) != 0) {
                ft_print("error : cd: wrong directory");
            }
        } else if (av != &av[i] && av[i] == NULL || strcmp(av[i], ";") == 0) {
            // 2 3 5 5
            pid = fork();
            if (pid == 0) {
                dup2(tmp, 0);
                if (ft_execute(i, tmp, av, ev)) {
                    return 1;
                }
            } else {
                close(tmp);
                waitpid(-1, 0, 0);
                tmp = dup(0);
            }
        } else if (av != &av[i] && strcmp(av[i], "|") == 0) {
            pipe(fd);
            pid = fork();
            if (pid == 0) {
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
                tmp = dup(0);
                close(fd[0]);
            }
        }
    }
    close(tmp);
    return 0;
}

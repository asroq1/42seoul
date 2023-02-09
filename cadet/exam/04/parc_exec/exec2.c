

static int exec(int i, char **av, char **ev) {
    int fd[2];
    int status;
    int pid;
    int next = 0;
    if (/* condition */) {
        /* code */
    }
    if (/* condition */) {
        /* code */
    }
    if (/* condition */) {
        /* code */
    }
    if (/* condition */) {
        /* code */
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
            ft_print("eror :  asd asd ");
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
}

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
    close(fd[1]);
    if (execve(*av, av, ev) == -1) {
        /* code */
    }
}
else {
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
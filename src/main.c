/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

extern const sysreg_t syscalls_g[];

int strace_exec(reg_t *arg, pid_t pid)
{
    unsigned short data;

    if (ptrace(PTRACE_GETREGS, pid, NULL, &arg->regs))
        printf("%s\n", "error");
    data = ptrace(PTRACE_PEEKTEXT, pid, arg->regs.rip, NULL);
    if (data == 0xFFFF)
        return (-1);
    else if (data == 0x050F) {
        printf("%s(", syscalls_g[arg->regs.rax].name);
        suit_print(arg);
        printf("\n");
    }
    ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    return (0);
}

int exec(pid_t pid, reg_t *arg)
{
    int status;

    waitpid(pid, &status, 0);
    while (WIFSTOPPED(status)) {
        strace_exec(arg, pid);
        waitpid(pid, &status, 0);
    }
    printf("%s %d %s\n", "+++ exited with", 0, "+++");
    return (0);
}

int get_strace(char **prog, int ac)
{
    char *pro[ac + 1];

    memcpy(pro, prog, ac * sizeof(char *));
    pro[ac] = NULL;
    if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
        printf("%s\n", "Bugging");
        return (-1);
    }
    kill(getpid(), SIGSTOP);
    execvp(pro[0], pro);
    return (0);
}

int strace(char **av, int ac)
{
    pid_t pid = fork();
    reg_t *arg = malloc(100);

    if (pid == 0)
        get_strace(av+1, ac-1);
    else {
        exec(pid, arg);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (0);
    if (av[1][0] == '-' && av[1][1] == '-' && av[1][2] == 'h'
        && av[1][3] == 'e' && av[1][4] == 'l' && av[1][5] == 'p')
        printf("%s\n", "USAGE: ./strace [-s] [-p <pid>|<command>]");
    else
        strace(av, ac);
    return (0);
}

/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** ly.h
*/

#ifndef MY_H_
    #define MY_H_

#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/user.h>

typedef struct reg_s
{
    struct user_regs_struct regs;
} reg_t;

typedef struct sysreg_s
{
    char *name;
    int param;
    char *nb_params[6];
    char *return_type;
} sysreg_t;

void suit_print(reg_t *arg);
void suit_print2(reg_t *arg);
int strace(char **av, int ac);
int get_strace(char **, int);
int exec(pid_t pid, reg_t *arg);
int strace_exec(reg_t *arg, pid_t pid);
void print_space();

#endif /* !MY_H_ */

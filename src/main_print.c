/*
** EPITECH PROJECT, 2019
** main_print2
** File description:
** main_print2
*/

#include "../include/my.h"

extern const sysreg_t syscalls_g[];

void print_space(void)
{
    printf(") = ");
}

void suit_print(reg_t *arg)
{
    if (syscalls_g[arg->regs.rax].param == 2)
        printf("0x%llx, 0x%llx", arg->regs.rdi, arg->regs.rsi);
    if (syscalls_g[arg->regs.rax].param == 3) {
        printf("0x%llx, 0x%llx, 0x%llx", arg->regs.rdi,
            arg->regs.rsi, arg->regs.rdx);
    }
    if (syscalls_g[arg->regs.rax].param == 4) {
        printf("0x%llx, 0x%llx, 0x%llx",
            arg->regs.rdi, arg->regs.rsi, arg->regs.rdx);
        printf(", 0x%llx", arg->regs.r8);
    }
    else
        suit_print2(arg);
}

void suit_print2(reg_t *arg)
{
    if (syscalls_g[arg->regs.rax].param == 1)
        printf("0x%llx", arg->regs.rdi);
    if (syscalls_g[arg->regs.rax].param == 5) {
            printf("0x%llx, 0x%llx, 0x%llx",
                arg->regs.rdi, arg->regs.rsi, arg->regs.rdx);
            printf(", 0x%llx, 0x%llx", arg->regs.r8, arg->regs.r9);
    }
    if (syscalls_g[arg->regs.rax].param == 6) {
        printf("0x%llx, 0x%llx, 0x%llx", arg->regs.rdi,
            arg->regs.rsi, arg->regs.rdx);
        printf(", 0x%llx, 0x%llx", arg->regs.r8, arg->regs.r9);
        printf(", 0x%llx", arg->regs.r10);
    }
    print_space();
}

/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static int check_signal(int sig, int wstatus)
{
    if (my_strcmp(strsignal(sig), "Interrupt") != 0) {
        my_dprintf(2, "%s", strsignal(sig));
        if (WCOREDUMP(wstatus))
            my_dprintf(2, " (core dumped)");
        my_dprintf(2, "\n");
        return 128 + sig;
    } else {
        my_dprintf(1, "\n");
        return 1;
    }
    return 0;
}

int stat_return(int wstatus)
{
    int sig = 0;
    int res = 0;

    if (WIFSIGNALED(wstatus)) {
        sig = WTERMSIG(wstatus);
        res = check_signal(sig, wstatus);
        if (res != 0)
            return res;
    }
    if (WIFEXITED(wstatus))
        return WEXITSTATUS(wstatus);
    return 0;
}

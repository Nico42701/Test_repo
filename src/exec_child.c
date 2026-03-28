/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

int check_is_dir(char ***str)
{
    struct stat st = {0};

    signal(SIGINT, SIG_DFL);
    if (stat((*str)[0], &st) == -1)
        return 0;
    if (S_ISDIR(st.st_mode)) {
        my_dprintf(2, "%s: Permission denied.\n", (*str)[0]);
        my_freelist(*str);
        exit(1);
    }
    return 0;
}

void exec_child(char **str, char **list, char ***env)
{
    check_is_dir(&str);
    execve(str[0], list, *env);
    check_error_message(str[0]);
    my_freelist(str);
    my_freelist(list);
    exit(1);
}

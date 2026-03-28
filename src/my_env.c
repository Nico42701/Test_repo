/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

void my_env(char ***env)
{
    int i = 0;

    while ((*env)[i] != 0) {
        my_dprintf(1, "%s\n", (*env)[i]);
        i++;
    }
    return;
}

/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

char *my_getenv(char ***env, const char *str)
{
    int len = 0;
    int i = 0;

    if (!*env || !str)
        return NULL;
    len = my_strlen(str);
    for (i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], str, len) == 0 &&
            (*env)[i][len] == '=') {
            return (*env)[i] + len + 1;
        }
    }
    return NULL;
}

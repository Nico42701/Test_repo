/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

int my_checkenv(char ***env, const char *name)
{
    int i = 0;
    char **data = NULL;

    while ((*env)[i] != NULL) {
        data = my_str_to_word_array((*env)[i], "=");
        if (data && data[0] && my_strcmp(data[0], name) == 0) {
            my_freelist(data);
            return i;
        }
        my_freelist(data);
        i++;
    }
    return -1;
}

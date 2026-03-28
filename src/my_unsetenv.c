/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static void my_shift(char ***env, int i)
{
    int j = i;

    free((*env)[i]);
    while ((*env)[j] != NULL) {
        (*env)[j] = (*env)[j + 1];
        j++;
    }
}

int my_unsetenv(char ***env, const char *name)
{
    int c_words = my_count_words(name, " \t");
    char **data = my_str_to_word_array(name, " \t");
    int i = 1;
    int idx = 0;

    if (c_words == 1) {
        my_dprintf(2, "unsetenv: Too few arguments.\n");
        my_freelist(data);
        return 1;
    }
    while (data[i] != NULL) {
        idx = my_checkenv(env, data[i]);
        if (idx != -1)
            my_shift(env, idx);
        i++;
    }
    my_freelist(data);
    return 0;
}

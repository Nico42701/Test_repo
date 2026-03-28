/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

int env_builtins(char ***env, char ***data, char *line)
{
    int res = 0;

    if (my_strcmp((*data)[0], "env") == 0 &&
        my_count_words(line, " ") == 1) {
        my_env(env);
        my_freelist(*data);
        return 0;
    }
    if (my_strcmp((*data)[0], "setenv") == 0) {
        res = my_setenv(env, line);
        my_freelist(*data);
        return res;
    }
    if (my_strcmp((*data)[0], "unsetenv") == 0) {
        res = my_unsetenv(env, line);
        my_freelist(*data);
        return res;
    }
    return 2;
}

int other_builtins(char ***env, char ***data, char *line)
{
    int res = 0;

    if (my_strcmp((*data)[0], "cd") == 0) {
        res = my_cd(env, line);
        my_freelist(*data);
        return res;
    }
    if (my_strcmp((*data)[0], "exit") == 0) {
        my_freelist(*data);
        return -1;
    }
    return 2;
}

int check_builtins(char ***env, char *line)
{
    char **data = my_str_to_word_array(line, " \t");
    int res = 0;

    if (!data)
        return 84;
    if (!data[0]) {
        my_freelist(data);
        return 84;
    }
    res = env_builtins(env, &data, line);
    if (res == 0 || res == 1)
        return res;
    res = other_builtins(env, &data, line);
    if (res == 0 || res == 1 || res == -1)
        return res;
    my_freelist(data);
    return 2;
}

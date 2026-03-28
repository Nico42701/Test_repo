/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

int check_alnum(char *line)
{
    char **data = my_str_to_word_array(line, " \t");

    if (!data)
        return 1;
    if (my_is_alpha(data[1][0]) == 0) {
        my_dprintf(2, "setenv: Variable name must begin with a letter.\n");
        my_freelist(data);
        return 1;
    }
    if (my_str_is_alnum(data[1]) == 0) {
        my_dprintf(2, "setenv: Variable name must contain ");
        my_dprintf(2, "alphanumeric characters.\n");
        my_freelist(data);
        return 1;
    }
    my_freelist(data);
    return 0;
}

int my_check_error(char ***env, int res, char *line)
{
    if (res < 2) {
        my_env(env);
        return 1;
    }
    if (res > 3) {
        my_dprintf(2, "setenv: Too many arguments.\n");
        return 84;
    }
    if (check_alnum(line) == 1)
        return 84;
    return 0;
}

int my_setenv(char ***env, char *line)
{
    int res = my_count_words(line, " \t");
    char **data = NULL;
    int check = my_check_error(env, res, line);

    if (check == 84)
        return 1;
    if (check == 1)
        return 0;
    data = my_str_to_word_array(line, " \t");
    if (res == 2)
        my_exec_setenv(env, data[1], NULL);
    else
        my_exec_setenv(env, data[1], data[2]);
    my_freelist(data);
    return 0;
}

int my_form_setenv(char ***env, const char *name, const char *value)
{
    int res = 0;
    char *line = NULL;

    if (!value)
        line = malloc(my_strlen("setenv") + my_strlen(name) + 2);
    else
        line = malloc(my_strlen("setenv") + my_strlen(name)
            + my_strlen(value) + 3);
    my_strcpy(line, "setenv");
    my_strcat(line, " ");
    my_strcat(line, name);
    if (value) {
        my_strcat(line, " ");
        my_strcat(line, value);
    }
    res = my_setenv(env, line);
    free(line);
    return res;
}

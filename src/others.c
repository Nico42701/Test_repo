/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

void free_data(char ***my_env, char **line)
{
    if (my_env && *my_env)
        my_freelist(*my_env);
    if (line && *line)
        free(*line);
}

void clean_args(char **args)
{
    for (int i = 0; args[i]; i++) {
        if (my_strcmp(args[i], "|") == 0 || my_strcmp(args[i], ">") == 0 ||
            my_strcmp(args[i], "<") == 0 || my_strcmp(args[i], ">>") == 0) {
            args[i] = NULL;
            break;
        }
    }
}

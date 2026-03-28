/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

char **my_listdup(char **list)
{
    int i = 0;
    char **new_list = NULL;

    while (list[i] != 0)
        i++;
    new_list = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++)
        new_list[j] = my_strdup(list[j]);
    new_list[i] = NULL;
    return new_list;
}

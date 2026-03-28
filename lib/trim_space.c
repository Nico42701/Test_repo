/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"


char *trim_space(char *str)
{
    int start = 0;
    int end = 0;

    while (str[start] == ' ')
        start++;
    end = my_strlen(str) - 1;
    while (end > start && str[end] == ' ')
        end--;
    str[end + 1] = '\0';
    return &str[start];
}

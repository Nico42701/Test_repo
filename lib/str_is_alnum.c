/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

int my_is_digit(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    return 0;
}

int my_is_alpha(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == '_'))
        return 1;
    return 0;
}

int my_str_is_alnum(const char *s)
{
    for (int i = 0; s[i]; i++)
        if (!my_is_digit(s[i]) && !my_is_alpha(s[i]))
            return 0;
    return 1;
}

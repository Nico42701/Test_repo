/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_strcspn
*/

#include "my.h"

char *my_strchr(const char *str, char c)
{
    int i = 0;

    if (!str)
        return NULL;
    while (str[i] != '\0') {
        if (str[i] == c)
            return (char *)&str[i];
        i++;
    }
    if (c == '\0')
        return (char *)&str[i];
    return NULL;
}

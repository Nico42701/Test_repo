/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *src)
{
    char *str = NULL;
    int len = 0;
    int i = 0;

    if (!src)
        return NULL;
    while (src[len] != '\0')
        len++;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    for (i = 0; i < len; i++)
        str[i] = src[i];
    str[len] = '\0';
    return str;
}

/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    dest[0] = src[0];
    while (src[a] != '\0') {
        a = a + 1;
        dest[a] = src[a];
    }
    return (dest);
}

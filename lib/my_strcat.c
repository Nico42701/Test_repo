/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;
    int b_count = 0;

    while (dest[a] != '\0') {
        a = a + 1;
    }
    a = a - 1;
    while (src[b_count] != '\0') {
        b_count = b_count + 1;
    }
    while (b <= b_count) {
        a = a + 1;
        dest[a] = src[b];
        b = b + 1;
    }
    dest[a] = '\0';
    return (dest);
}

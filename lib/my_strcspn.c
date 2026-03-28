/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_strcspn
*/

#include "my.h"

static int my_loop(char const *str, char const *charset, int i)
{
    int j = 0;

    while (charset[j] != '\0') {
        if (str[i] == charset[j])
            return i;
        j++;
    }
    return -1;
}

int my_strcspn(char const *str, char const *charset)
{
    int i = 0;
    int res = 0;

    while (str[i] != '\0') {
        res = my_loop(str, charset, i);
        if (res != -1)
            return res;
        i++;
    }
    return i;
}

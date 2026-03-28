/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_putstr
*/

#include "my_printf.h"

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

int my_dputstr(int fd, char const *str)
{
    if (str == NULL)
        write(fd, "(null)", my_strlen("(null)"));
    else
        write(fd, str, my_strlen(str));
    return 0;
}

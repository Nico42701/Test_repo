/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_dputvoid
*/

#include "my_printf.h"

int my_dputvoid(int fd, void *data)
{
    my_dputstr(fd, (char *)data);
    return 0;
}

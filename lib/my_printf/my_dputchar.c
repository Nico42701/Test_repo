/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_putchar
*/

#include "my_printf.h"

int my_dputchar(int fd, char c)
{
    write(fd, &c, 1);
    return 0;
}

/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_printf
*/

#include "my_printf.h"

int my_dprintf(int fd, const char *format, ...)
{
    va_list args;
    int ret = 0;

    va_start(args, format);
    ret = my_vdprintf(fd, format, args);
    va_end(args);
    return ret;
}

/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_printf
*/

#include "my_printf.h"

static int printf_detect_flag(int fd, const char *format, int i, va_list args)
{
    if (format[i + 1] == '\0')
        return 0;
    if (format[i + 1] == '%') {
        my_dputchar(fd, '%');
        return 1;
    }
    if (format[i + 1] == 's') {
        my_dputstr(fd, va_arg(args, char *));
        return 1;
    }
    if (format[i + 1] == 'c') {
        my_dputchar(fd, (char)va_arg(args, int));
        return 1;
    }
    if (format[i + 1] == 'd' || format[i + 1] == 'i') {
        my_dputnbr(fd, va_arg(args, int));
        return 1;
    }
    my_dputchar(fd, '%');
    return !my_dputchar(fd, format[i + 1]);
}

int my_vdprintf(int fd, const char *format, va_list args)
{
    int i = 0;
    int jump = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            jump = printf_detect_flag(fd, format, i, args);
            i += jump;
        } else
            my_dputchar(fd, format[i]);
        i++;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>
    #include <unistd.h>

int my_dputchar(int fd, char c);
int my_dputnbr(int fd, int nb);
int my_dputvoid(int fd, void *data);
int my_dputstr(int fd, char const *str);
int my_vdprintf(int fd, const char *format, va_list args);
int my_dprintf(int fd, const char *format, ...);
int my_printf(const char *format, ...);

#endif

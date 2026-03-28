/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_putnbr
*/

#include "my_printf.h"

int my_dputnbr(int fd, int nb)
{
    if (nb < 0) {
        my_dputchar(fd, '-');
        nb = -nb;
    }
    if (nb >= 10)
        my_dputnbr(fd, nb / 10);
    my_dputchar(fd, '0' + (nb % 10));
    return 0;
}

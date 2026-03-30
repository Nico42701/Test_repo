/*
** EPITECH PROJECT, 2026
** Lib
** File description:
** my_itoa
*/

#include <stdlib.h>
#include <unistd.h>

static int count_digits(int n)
{
    int count = 0;

    if (n <= 0)
        count++;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return (count);
}

static void verif_negative(long *nb, char **str)
{
    if (*nb < 0) {
        (*str)[0] = '-';
        *nb = -*nb;
    }
}

char *my_itoa(int n)
{
    char *str = NULL;
    int len = 0;
    long nb = 0;

    nb = n;
    len = count_digits(n);
    str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    verif_negative(&nb, &str);
    if (nb == 0)
        str[0] = '0';
    while (nb > 0) {
        str[len - 1] = (nb % 10) + '0';
        nb /= 10;
        len--;
    }
    return str;
}

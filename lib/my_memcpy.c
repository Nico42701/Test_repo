/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include <unistd.h>

void *my_memcpy(void *dest, const void *src, int n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for (int i = 0; i < n; i++)
        d[i] = s[i];
    return dest;
}

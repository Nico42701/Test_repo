/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

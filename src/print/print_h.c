/*
** EPITECH PROJECT, 2026
** -h
** File description:
** -h
*/

#include "crocus.h"

int print_h(int fd)
{
    write(fd, "Usage: ./crocus -n number [-s string]\n", 38);
    write(fd, "-n number: to display in 'ASCII art', it must be >= 0\n", 54);
    write(fd, "-s string: each digit will be represented by the charater", 57);
    write(fd, " from string whose index is the digit (modulo the size ", 55);
    write(fd, "of the string). Default: '0' (zero).\n", 37);
    return 0;
}

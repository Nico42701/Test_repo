/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "crocus.h"

int main(int ac, char **av)
{
    crocus_t cr = {0};

    if (ac == 1)
        return print_error(2);
    if (ac == 2) {
        if (strcmp(av[1], "-h") == 0)
            return print_h(1);
        return print_error(2);
    }
    if (parser(av, &cr) == 84)
        return 84;
    print_crocus(cr.number, cr.to_fill);
    free_crocus(&cr);
    return 0;
}

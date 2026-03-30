/*
** EPITECH PROJECT, 2026
** src
** File description:
** parser.c
*/

#include "crocus.h"

static int check_flag(char *line)
{
    if (line[0] == '-') {
        if (line[1] == '\0')
            return 84;
        if ((line[1] == 'n' && line[2] == '\0') ||
            (line[1] == 's' && line[2] == '\0'))
            return 0;
        else
            return 84;
    }
    return 0;
}

static int check_flag_all(char **av)
{
    int n = 0;
    int s = 0;

    for (int i = 0; av[i]; i++)
        if (check_flag(av[i]) == 84)
            return 84;
    for (int j = 0; av[j]; j++) {
        if (strcmp(av[j], "-n") == 0)
            n++;
        if (strcmp(av[j], "-s") == 0)
            s++;
    }
    if (n > 1 || s > 1)
        return 84;
    return 0;
}

int parser(char **av, crocus_t *cr)
{
    int find_n = 0;

    cr->to_fill = strdup("0");
    if (!cr->to_fill)
        return 84;
    if (check_flag_all(av) == 84)
        return 84;
    if (find_flag_n(av, cr) == 1)
        find_n++;
    if (find_n == 0) {
        free(cr->to_fill);
        return 84;
    }
    find_flag_s(av, cr);
    return 0;
}

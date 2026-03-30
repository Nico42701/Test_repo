/*
** EPITECH PROJECT, 2026
** find n
** File description:
** find n
*/

#include "crocus.h"

static int check_number(char *line)
{
    if (!line || line[0] == '\0')
        exit(84);
    for (int i = 0; line[i]; i++) {
        if (line[i] >= 48 && line[i] <= 57)
            continue;
        else
            exit(84);
    }
    return 0;
}

static int check_flag_n(char *line, char *to_check, crocus_t *cr)
{
    int find_n = 0;

    if (strcmp(line, "-n") == 0) {
        if (!to_check)
            exit(84);
        if (check_number(to_check) == 0)
            find_n = 1;
    }
    if (find_n == 1) {
        cr->number = strdup(to_check);
        if (!cr->number)
            return 84;
        return 1;
    }
    return 0;
}

int find_flag_n(char **av, crocus_t *cr)
{
    if (!av)
        return 0;
    for (int i = 1; av[i]; i++) {
        if (check_flag_n(av[i], av[i + 1], cr) == 1)
            return 1;
    }
    return 0;
}

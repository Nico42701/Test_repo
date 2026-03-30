/*
** EPITECH PROJECT, 2026
** find s
** File description:
** find s
*/

#include "crocus.h"

static int check_string(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] >= 97 && line[i] <= 122)
            continue;
        else
            return 1;
    }
    return 0;
}

static void check_arg(char *str, crocus_t *cr)
{
    if (!str || !str[0]) {
        free_crocus(cr);
        exit(84);
    }
}

static int check_flag_s(char *line, char *to_check, crocus_t *cr)
{
    int find_s = 0;

    if (strcmp(line, "-s") == 0) {
        check_arg(to_check, cr);
        if (check_string(to_check) == 0)
            find_s = 1;
        else {
            free(cr->number);
            exit(84);
        }
    }
    if (find_s == 1) {
        free(cr->to_fill);
        cr->to_fill = strdup(to_check);
        if (!cr->to_fill)
            return 84;
        return 1;
    }
    return 0;
}

int find_flag_s(char **av, crocus_t *cr)
{
    if (!av)
        return 0;
    for (int i = 1; av[i]; i++) {
        if (check_flag_s(av[i], av[i + 1], cr) == 1)
            return 1;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

int **init_map(graph_t *conf)
{
    int **tab = malloc(sizeof(int *) * conf->length_max);

    if (!tab)
        return NULL;
    for (int i = 0; i < conf->length_max; i++) {
        tab[i] = malloc(sizeof(int) * conf->length_max);
        if (!tab[i]) {
            free_list(&tab);
            return NULL;
        }
    }
    for (int y = 0; y < conf->length_max; y++)
        for (int x = 0; x < conf->length_max; x++)
            tab[y][x] = 0;
    return tab;
}

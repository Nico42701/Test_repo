/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

void free_list(int ***tab)
{
    for (int i = 0; (*tab)[i]; i++)
        free((*tab)[i]);
    free(*tab);
}

void free_2d_map(sfVector2f **map, graph_t *conf)
{
    if (!map)
        return;
    for (int y = 0; y < conf->length_max; y++)
        free(map[y]);
    free(map);
}

void free_2d_tab(int **tab, graph_t *conf)
{
    if (!tab)
        return;
    for (int y = 0; y < conf->length_max; y++)
        free(tab[y]);
    free(tab);
}

/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

void update_map(sfVector2f ***map_2d, graph_t *conf, int **tab, sfView **view)
{
    free_2d_map(*map_2d, conf);
    *map_2d = create_2d_map(tab, conf);
    sfView_setSize(*view, (sfVector2f){800 * conf->zoom, 600 * conf->zoom});
    sfView_setCenter(*view, conf->pos_view);
}

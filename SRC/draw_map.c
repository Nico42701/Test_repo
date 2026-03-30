/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

int draw_horizontal(sfRenderWindow *window,
    sfVector2f **map, graph_t *conf, int **tab)
{
    sfVertexArray *line = NULL;

    for (int y = 0; y < conf->length_max; y++)
        for (int x = 0; x < conf->length_max - 1; x++) {
            line = create_line(&map[y][x], &map[y][x + 1], tab[y][x]);
            sfRenderWindow_drawVertexArray(window, line, NULL);
            sfVertexArray_destroy(line);
        }
    return 0;
}

int draw_vertical(sfRenderWindow *window,
    sfVector2f **map, graph_t *conf, int **tab)
{
    sfVertexArray *line = NULL;

    for (int y = 0; y < conf->length_max - 1; y++)
        for (int x = 0; x < conf->length_max; x++) {
            line = create_line(&map[y][x], &map[y + 1][x], tab[y][x]);
            sfRenderWindow_drawVertexArray(window, line, NULL);
            sfVertexArray_destroy(line);
        }
    return 0;
}

int draw_2d_map(sfRenderWindow *window,
    sfVector2f **map, graph_t *conf, int **tab)
{
    draw_horizontal(window, map, conf, tab);
    draw_vertical(window, map, conf, tab);
    return 0;
}

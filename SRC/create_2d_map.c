/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

sfVector2f project_iso_point(int x, int y, int z, graph_t *conf)
{
    sfVector2f point = {0};
    double iso_x = 45.0 * M_PI / 180.0;
    double iso_y = 30.0 * M_PI / 180.0;
    float cx = conf->length_max / 2.0f;
    float cy = conf->length_max / 2.0f;
    float tx = x - cx;
    float ty = y - cy;
    float rx = tx * cos(conf->world_angle) - ty * sin(conf->world_angle);
    float ry = tx * sin(conf->world_angle) + ty * cos(conf->world_angle);

    rx += cx;
    ry += cy;
    point.x = (rx - ry) * cos(iso_x);
    point.y = (rx + ry) * sin(iso_y) - z;
    return point;
}

sfVector2f **create_iso_map(sfVector2f **map_2d, int **map_3d, graph_t *conf)
{
    sfVector2f point = {0};

    for (int y = 0; y < conf->length_max; y++) {
        for (int x = 0; x < conf->length_max; x++) {
            point = project_iso_point(
                x * 64,
                y * 64,
                map_3d[y][x],
                conf
            );
            map_2d[y][x] = point;
        }
    }
    return map_2d;
}

sfVector2f **create_2d_map(int **map_3d, graph_t *conf)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * conf->length_max);

    if (!map_2d)
        return NULL;
    for (int y = 0; y < conf->length_max; y++) {
        map_2d[y] = malloc(sizeof(sfVector2f) * conf->length_max);
        if (!map_2d[y])
            return NULL;
    }
    map_2d = create_iso_map(map_2d, map_3d, conf);
    return map_2d;
}

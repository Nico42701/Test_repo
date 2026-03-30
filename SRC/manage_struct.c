/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

int init_views(sfView **view, sfRenderWindow **window)
{
    *view = sfView_create();
    if (!*view)
        return 84;
    sfView_setSize(*view, (sfVector2f){800, 600});
    sfView_setCenter(*view, (sfVector2f){400, 300});
    sfRenderWindow_setFramerateLimit(*window, 60);
    return 0;
}

int init_struct(graph_t *conf, sfRenderWindow **window, int ***tab,
    sfVector2f ***map_2d)
{
    sfVideoMode mode = {800, 600, 32};
    sfVector2u size = {0};

    *window = sfRenderWindow_create(mode, "MyWorld", sfResize | sfClose, NULL);
    if (!*window)
        return 84;
    size = sfRenderWindow_getSize(*window);
    conf->pos_view.x = size.x / 2.0f;
    conf->pos_view.y = size.y / 2.0f;
    conf->length_max = 200;
    conf->range = 800.0f;
    conf->zoom = 1.0f;
    conf->world_angle = 0.0f;
    conf->font = sfFont_createFromFile("fonts/Blazeberg.otf");
    *tab = init_map(conf);
    if (!*tab)
        return 84;
    *map_2d = create_2d_map(*tab, conf);
    return 0;
}

void load_click_struct(click_t *click, int ***tab, graph_t *conf,
    sfVector2f **map_2d)
{
    click->conf = conf;
    click->tab = tab;
    click->map = map_2d;
}

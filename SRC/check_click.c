/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

int is_point_clicked(sfVector2f *point,
    sfVector2f *mouse, float radius)
{
    float dx = point->x - mouse->x;
    float dy = point->y - mouse->y;

    return (dx * dx + dy * dy) <= (radius * radius);
}

void update_point(click_t *click, int y, int x)
{
    if (is_point_clicked(&click->map[y][x],
            &click->mouse, click->conf->range))
        (*click->tab)[y][x] += click->buttons.state_lower_raise;
}

void browse_map(click_t *click)
{
    for (int y = 0; y < click->conf->length_max; y++)
        for (int x = 0; x < click->conf->length_max; x++)
            update_point(click, y, x);
}

void manage_click_on_map(sfRenderWindow *window,
    sfView *view, click_t *click)
{
    sfVector2i pixel = {0};

    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    pixel = sfMouse_getPositionRenderWindow(window);
    click->mouse = sfRenderWindow_mapPixelToCoords(window, pixel, view);
    browse_map(click);
}

/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

sfColor get_color_from_height(int z)
{
    if (z > 0)
        return sfWhite;
    if (z < 0)
        return sfBlue;
    return sfGreen;
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2, int z)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfColor my_color = get_color_from_height(z);
    sfVertex vertex1 = {.position = *point1, .color = my_color};
    sfVertex vertex2 = {.position = *point2, .color = my_color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return vertex_array;
}

void end_loop(sfRenderWindow **window, graph_t *conf, int ***tab,
    sfVector2f ***map_2d)
{
    free_2d_tab(*tab, conf);
    free_2d_map(*map_2d, conf);
    sfRenderWindow_destroy(*window);
}

void init_buttons_texture(click_t *clicks)
{
    sfVector2u len = {0};

    clicks->buttons.texture_lower_on = sfTexture_createFromFile("sprites/Button_lower_on.png", NULL);
    clicks->buttons.texture_lower_off = sfTexture_createFromFile("sprites/Button_lower_off.png", NULL);
    clicks->buttons.texture_raise_on = sfTexture_createFromFile("sprites/Button_raise_on.png", NULL);
    clicks->buttons.texture_raise_off = sfTexture_createFromFile("sprites/Button_raise_off.png", NULL);
    clicks->buttons.sprite_lower = sfSprite_create();
    clicks->buttons.sprite_raise = sfSprite_create();
    clicks->buttons.state_lower_raise = 1;
    clicks->buttons.range_text = sfText_create();
    sfSprite_setScale(clicks->buttons.sprite_raise, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(clicks->buttons.sprite_raise, (sfVector2f){0, 0});
    sfSprite_setScale(clicks->buttons.sprite_lower, (sfVector2f){0.5, 0.5});
    len = sfTexture_getSize(clicks->buttons.texture_raise_on);
    sfSprite_setPosition(clicks->buttons.sprite_lower, (sfVector2f){(len.x * 0.5) + 5, 0});
}

int main(void)
{
    sfRenderWindow *window = {0};
    graph_t conf = {0};
    click_t click = {0};
    int **tab = 0;
    sfVector2f **map_2d = {0};
    sfView *view = {0};

    if (init_struct(&conf, &window, &tab, &map_2d) == 84 ||
        init_views(&view, &window) == 84)
        return 84;
    init_buttons_texture(&click);
    while (sfRenderWindow_isOpen(window)) {
        manage_events(window, &conf, &click);
        load_click_struct(&click, &tab, &conf, map_2d);
        manage_click_on_map(window, view, &click);
        update_map(&map_2d, &conf, tab, &view);
        clear_disp(window, view);
        update_disp(window, map_2d, &conf, tab, &click, view);
    }
    end_loop(&window, &conf, &tab, &map_2d);
    return 0;
}
